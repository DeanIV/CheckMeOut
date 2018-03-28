#include "order.h"

order::order() {
  tax = 0.0725;
  closed = false;
  Observable item;
}

order::order(double tax) {
  this->tax = tax;
  closed = false;
}

void order::addItem(item i) {//customer and cashier views updated
  if( !closed )
  {
    itemList.push_back(i);
    item.update();
    item.notifyObservers();
  }
}

std::vector<item> order::getItems() {
  return itemList;
}

double order::getSubtotal() {
  double subtotal = 0;
  for(int i = 0; i < itemList.size(); i++) {
    subtotal += itemList[i].getPrice();
  }
  return subtotal;
}

double order::getTax() {
  return tax;
}

double order::getTotal() {
  return getSubtotal() * (1 + tax);
}

double order::balance(double paid) {
  closed = true;
  return getTotal() - paid;
}
