#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <stdio.h>

#include "Item.h"
#include "ItemSword.h"

class Inventory {
  public:
    Inventory();
    virtual ~Inventory();

    bool isInBounds(int index);

    void clear();
    void fill(int first, int last);
    void empty();

    void setItemInSlot(int slot, Item* item);
    Item* getItemInSlot(int slot);

  protected:

  private:
    /* Different containers for comparison. This is here for reference, listed
       from slowest to fastest. A plain array is the fastest solution here.
       Might switch to a vector in the future so that inventories could have a
       variable size. */
    //std::map<int, Item*> items;
    //boost::container::flat_map<int, Item*> items;
    //std::deque<Item*> items;
    //std::vector<Item*> items;

    static const int invSize = 10;
    Item* items[invSize];
};

#endif // INVENTORY_H
