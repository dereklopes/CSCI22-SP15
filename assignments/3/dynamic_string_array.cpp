/* 
 * File Name: dynamic_string_array.cpp
 * Author: Derek Lopes
 * Sources: Luke Sathrum, Absolute C++ by Walter Savich
 */

#include "dynamic_string_array.h"

/* Default constructor to initialize the array to size 10 and elements to NULL
 * Sets amount of elements to 0.
 */
DynamicStringArray::DynamicStringArray() {
  max_capacity = 10;
  string_array = new string*[max_capacity];    
  size = 0;
  for (unsigned int i = 0; i < max_capacity; i++) {
    string_array[i] = NULL;
  }
} 
/* Constructor to initialize the array to provided size and elements to NULL.
 * Defaults to size 10 if parameter is invalid.
 * @param unsigned int - size the array should be initialized
 */
DynamicStringArray::DynamicStringArray(unsigned int size) {
  max_capacity = size;
  string_array = new string*[max_capacity];    
  size = 0;
  for (unsigned int i = 0; i < max_capacity; i++) {
    string_array[i] = NULL;
  }
}

/* Destructor to free all memory allocated to the arrays and strings.
 */
DynamicStringArray::~DynamicStringArray() {
  size = 0;
  for (unsigned int i = 0; i < max_capacity; i++) {
    string_array[i] = NULL;
  }
  delete[] string_array;
}

/* Returns a pointer to the string at the location provided.
 * If the location is invalid, throws "Invalid Location".
 * @param unsigned int - the location to find the string
 * @return string* - pointer to the string at provided location
 */
string* DynamicStringArray::At(unsigned int location) {
  if (location > size)
    throw string("Invallid Location");
  return string_array[location];
}

/* Returns a pointer to the first string in the array.
 * Throws "Array Empty" if the array is empty.
 * @return string* - pointer to the first string in the array.
 */
string* DynamicStringArray::GetFirst() {
  if (size != 0)
    throw string("Invallid Location");
  return string_array[0];
}

/* Returns a pointer to the last string in the array.
 * Throws "Array Empty" if the array is empty.
 * @return string* - pointer to the last string in the array.
 */
string* DynamicStringArray::GetLast() {
  if (size != 0)
    throw string("Invallid Location");
  return string_array[size];
}

/* Adds the provided string to the front of the array.
 * If the array is full, the capacity is increased first.
 * @param string* - string to add to the array
 */
void DynamicStringArray::AddFront(string* to_add) {
  if (size == max_capacity) {
    IncreaseCapacity();
  }
  string** string_array_2 = new string*[max_capacity];
  string_array_2[0] = to_add;
  for (unsigned int i = 1; i < max_capacity; i++) {
    string_array_2[i] = string_array[i - 1];
  }
  delete[] string_array;
  string_array = string_array_2;
  string_array_2 = NULL;
  size++;
}

/* Adds the provided string to the back of the array.
 * If the array is full, the capacity is increased frist.
 * @param string* - string to add to the array
 */
void DynamicStringArray::AddBack(string* to_add) {
  if (size == max_capacity) {
    IncreaseCapacity();
  }
  string_array[size] = to_add;
}

/* Deletes the first element in the array.
 * If the array is empty, the string "Array Empty" is thrown.
 */
void DynamicStringArray::DeleteFront() {
  if (size == 0)
    throw string("Array Empty");
  string** string_array_2 = new string*[max_capacity];
  for (unsigned int i = 1; i < size; i++) {
    string_array_2[i - 1] = string_array[i];
  }
  delete[] string_array;
  string_array = string_array_2;
  string_array_2 = NULL;
}

/* Deletes the last element in the array.
 * If the array is empty, the string "Array Empty" is thrown.
 */
void DynamicStringArray::DeleteBack() {
  string_array[size - 1] = NULL;
  size--;
}

/* Const function that gets the current size of the array.
 * @return unsigned int - the current size of the array
 */
unsigned int DynamicStringArray::GetSize() const {
  return size;
}
  
/* Const function that gets the current maximum capacity of the array.
 * @return unsigned int - the maximum capacity of the array
 */
unsigned int DynamicStringArray::GetCapacity() const {
  return max_capacity;
}

/* Const function. Checks to see if the array is empty.
 * @return bool - returns true if array is empty (size 0)
 */
bool DynamicStringArray::Empty() const {
  if (size == 0) {
    return true;
  } else {
    return false;
  }
}
  
/* Deletes all of the strings in the array and sets size to 0.
 */
void DynamicStringArray::Clear() {
  for (unsigned int i = 0; i < size; i++) {
    string_array[i] = NULL;
  }
  size = 0;
}

/* Sorts the array alphabetically A-Z, case insensitive.
 * @uses ToUpper()
 */
void DynamicStringArray::Sort() {

}

/* Returns a string containing all the strings in the array, comma separated.
 * @return string - a string of all the strings in the array
 */
string DynamicStringArray::ToString() {
  stringstream ss;
  for (unsigned int i = 0; i < (size - 1); i++) {
    ss << string_array[i] << ", ";
  }
  ss << string_array[size - 1];
  return ss.str();
}

/* Overloaded Friend Operator for << to output a comma separated list of the strings
 */
ostream& operator <<(ostream& out, const DynamicStringArray& the_array) {
  out << the_array.ToString();  
  return out;
}

/* Increases the capacity of the array by 10.
 */
void DynamicStringArray::IncreaseCapacity() {
  string** string_array_2 = new string*[max_capacity + 10];
  for (unsigned int i = 0; i < size; i++) {
    string_array_2[i] = string_array[i];
  }
  for (unsigned int i = size; i < max_capacity; i++) {
    string_array_2[i] = NULL;
  }
  delete[] string_array;
  string_array = string_array_2;
  string_array_2 = NULL;
}
