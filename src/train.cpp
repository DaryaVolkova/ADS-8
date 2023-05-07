// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :countOp(0), first(nullptr) {}
void Train::addCage(bool light) {
    if (!first) {
        first = new Cage;
        first->light = light;
        first->next = nullptr;
        first->prev = nullptr;
    } else {
        if (!first->next) {
        Cage* vst = new Cage;
        vst->light = light;
        vst->prev = vst->next = first;
        first->next = vst;
        first->prev = vst;
    } else {
        Cage* cur = first;
        while (cur->next != first)
            cur = cur->next;
            Cage* vst = new Cage;
            vst->light = light;
            vst->next = first;
            vst->prev = cur;
            cur->next = vst;
            first->prev = vst;
        }
    }
}

int Train::getLength() {
    int Length = 1;
    Cage* cur = first;
    if (!cur->light)
        cur->light = true;
    cur = cur->next;
    countOp++;
    while (true) {
        if (!cur->light) {
        Length++;
        cur = cur->next;
        countOp++;
        } else {
            cur->light = false;
            int tmp_Length = Length;
            while (Length) {
                cur = cur->prev;
                Length--;
                countOp++;
            }
            if (!cur->light) {
                return tmp_Length;
            } else {
                while (tmp_Length) {
                    cur = cur->next;
                    tmp_Length--;
                    Length++;
                    countOp++;
                }
            }
        }
    }
}

int Train::getOpCount() {
    return countOp;
}
