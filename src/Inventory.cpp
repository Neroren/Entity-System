#include "Inventory.h"

Inventory::Inventory() {
    clear();
    fill(0, 5);
}

Inventory::~Inventory() {
    empty();
}

bool Inventory::isInBounds(int index) {
    if (index > invSize || index < 0)
        return false;

    return true;
}

void Inventory::clear() {
    for (int i = 0; i < invSize; ++i)
        items[i] = 0;
}

void Inventory::fill(int first, int last) {
    if (!isInBounds(first) || !isInBounds(last)) {
        printf("fill(): Out of bounds. Ranges are from 0 to %d\n", invSize);
        return;
    }

    for (int i = first; i < last; ++i) {
        Item* item = (Item*) new ItemSword;
        items[i] = item;
    }
}

void Inventory::empty() {
    for (int i = 0; i < invSize; ++i) {
        if (items[i]) {
            delete items[i];
        }
    }

    clear();
}

void Inventory::setItemInSlot(int slot, Item* item) {
    if (!isInBounds(slot)) {
        printf("setItemInSlot(): Out of bounds. Ranges are from 0 to %d\n", invSize);
        return;
    }

    // Delete previous item
    if (items[slot]) {
        delete items[slot];
    }

    items[slot] = item;
}

Item* Inventory::getItemInSlot(int slot) {
    if (!isInBounds(slot)) {
        printf("getItemInSlot(): Out of bounds. Ranges are from 0 to %d\n", invSize);
        return 0;
    }

    return items[slot];
}
