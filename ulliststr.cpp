#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
    if (head_ == NULL){ //empty list
      Item* temp = new Item;
      temp->val[0] = val;
      temp->last = 1; 
      head_ = temp;
      tail_ = temp;
    }
    else{
      if (tail_->last < 10){
        tail_->val[tail_->last] = val;
        tail_->last += 1;
      }
      else{
        Item* temp2 = new Item;
        temp2->val[0] = val;
        temp2->last = 1;
        temp2->prev = tail_;
        tail_->next = temp2;
        tail_ = temp2;
        
      }
    }
  size_++;
}

void ULListStr::push_front(const std::string& val)
{
    if (head_ == NULL){ //empty list
      Item* temp = new Item;
      temp->val[9] = val;
      temp->first = 9;
      temp->last = 10; 
      head_ = temp;
      tail_ = temp;
      
    }
    else{
      if (head_->first > 0){ //have space in the head item
        head_->val[head_->first -1] = val;
        head_->first -= 1;
        
      }
      else{ // dont have space
        Item* temp2 = new Item;
        temp2->val[9] = val;
        temp2->first = 9;
        temp2->last = 10;
        temp2->next = head_;
        head_->prev = temp2;
        head_ = temp2;
        
      }
    }
    size_++;
}

void ULListStr::pop_front()
{
  if (head_ != NULL){ //not a empty list
    if (head_->first != head_->last){ // not a empty item
      head_->val[head_->first] = "";
      head_->first += 1;
      size_ -= 1;

      if (head_->first == head_->last){ //check if item is empty after pop
        // deallocate
        if (size_ == 0){
          //check if the item is the last item
          delete head_;
          head_ = NULL;
          tail_ = NULL;
          
        }
        else{
          head_->next->prev = NULL;
          Item* temp = head_;
          head_ = head_->next;
          delete temp;
        }
        
      }
    }
  }
}

void ULListStr::pop_back()
{
  if (tail_ != NULL){ //not empty list
    if (tail_->first != tail_->last){ //not empty tail item
      tail_->val[tail_->last-1] = "";
      tail_->last -= 1;
      size_ -= 1;

      if (tail_->first == tail_->last){ //empty tail item
        // deallocate
        if (size_ == 0){
          //check if the item is the last item
          delete tail_;         
          head_ = NULL;
          tail_ = NULL;
          
        }
        else{
          // not the last item
          tail_->prev->next = NULL;
          Item* temp = tail_;
          tail_ = tail_->prev;
          delete temp;
        }
       
      }
    }
  }
}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  size_t count = 0;
  Item* ptr = head_;
  if (ptr == NULL){
    return NULL;
  }

  count += ptr->last - ptr->first;
  while (loc >= count){
    if (ptr->next == NULL){
      return NULL;
    }
    ptr = ptr->next;
    count += ptr->last - ptr->first;
  }
  size_t index = ptr->last - (count - loc);
  return &(ptr->val[index]);

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
