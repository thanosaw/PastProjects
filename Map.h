/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//map.h


#include <string>

using KeyType= std::string;
using ValueType = double;
const int DEFAULT_MAX_ITEMS = 250;

class Map
{
  public:
    Map()
    : asize(0)
    {}
    // Create an empty map (i.e., one with no key/value pairs)

    bool empty() const {
        if (asize==0){
            return true;
        }
        return false;
    }  // Return true if the map is empty, otherwise false.

    int size() const{
        return asize;
    }    // Return the number of key/value pairs in the map.

    bool insert(const KeyType& key, const ValueType& value){
        if (!contains(key)&&size()<DEFAULT_MAX_ITEMS){
            arr[size()].k = key;
            arr[size()].v = value;
            asize++;
            return true;
        }
        else
        return false;
    }
      // If key is not equal to any key currently in the map, and if the
      // key/value pair can be added to the map, then do so and return true.
      // Otherwise, make no change to the map and return false (indicating
      // that either the key is already in the map, or the map has a fixed
      // capacity and is full).

    bool update(const KeyType& key, const ValueType& value){
        if (!contains(key)){
            return false;
        }
        int location=0;
        for (int i=0;i<size();i++){
            if (arr[i].k==key){
                location = i;
            }
        }
        arr[location].v = value;
        return true;
    }
      // If key is equal to a key currently in the map, then make that key no
      // longer map to the value it currently maps to, but instead map to
      // the value of the second parameter; return true in this case.
      // Otherwise, make no change to the map and return false.

    bool insertOrUpdate(const KeyType& key, const ValueType& value){
        if (!contains(key)&&size()<DEFAULT_MAX_ITEMS){
            arr[size()].k = key;
            arr[size()].v = value;
            asize++;
            return true;
        }
        if (!contains(key)){
            return false;
        }
        int location=0;
        for (int i=0;i<size();i++){
            if (arr[i].k==key){
                location = i;
            }
        }
        arr[location].v = value;
        return true;
    }
      // If key is equal to a key currently in the map, then make that key no
      // longer map to the value it currently maps to, but instead map to
      // the value of the second parameter; return true in this case.
      // If key is not equal to any key currently in the map and if the
      // key/value pair can be added to the map, then do so and return true.
      // Otherwise, make no change to the map and return false (indicating
      // that the key is not already in the map and the map has a fixed
      // capacity and is full).

    bool erase(const KeyType& key){
        if (!contains(key)){
            return false;
        }
        int location=0;
        for (int i=0;i<size();i++){
            if (arr[i].k==key){
                location = i;
            }
        }
        arr[location]=arr[asize--];
        asize--;
        return true;
    }
      // If key is equal to a key currently in the map, remove the key/value
      // pair with that key from the map and return true.  Otherwise, make
      // no change to the map and return false.
     
    bool contains(const KeyType& key) const{
        for (int i=0;i<size();i++){
            if (arr[i].k == key){
                return true;
            }
        }
        return false;
    }
      // Return true if key is equal to a key currently in the map, otherwise
      // false.
     
    bool get(const KeyType& key, ValueType& value){
        if (!contains(key)){
            return false;
        }
        int location=0;
        for (int i=0;i<size();i++){
            if (arr[i].k==key){
                location = i;
            }
        }
        value = arr[location].v;
        return true;
    }
    
      // If key is equal to a key currently in the map, set value to the
      // value in the map that that key maps to, and return true.  Otherwise,
      // make no change to the value parameter of this function and return
      // false.
     
    bool get(int i, KeyType& key, ValueType& value) const{
        if (0<=i&&i<size()){
            key = arr[i].k;
            value = arr[i].v;
            return true;
        }
        return false;
    }
      // If 0 <= i < size(), copy into the key and value parameters the
      // key and value of one of the key/value pairs in the map and return
      // true.  Otherwise, leave the key and value parameters unchanged and
      // return false.  (See below for details about this function.)

    void swap(Map& other){
        // copy constructor
        
    }
      // Exchange the contents of this map with the other one.
    private:
    struct data{
        KeyType k;
        ValueType v;
    };
    data arr[DEFAULT_MAX_ITEMS];
    int asize;
    
};
