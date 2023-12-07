/**
 * @param a: a pointer to a pointer to void
 * @param b: a pointer to a pointer to void
 * @return: void
 * @brief: swap the values of the two pointers
*/
void swap(void** a, void** b) {
    void* temp = *a;
    *a = *b;
    *b = temp;
}