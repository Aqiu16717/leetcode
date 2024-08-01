#include <iostream>
using namespace std;

struct Bucket {
    Bucket() = default;
    Bucket(int size, int capacity) : size_(size), capacity_(capacity) {}

    int size_;
    int capacity_;
};

int main()
{
    Bucket b3(0, 3);
    Bucket b5(0, 5);
    
    // 1. **将5公斤的桶装满**。现在，5公斤的桶里有5公斤的水，3公斤的桶是空的
    b5.size_ = b5.capacity_;
    // 2. **将5公斤桶里的水倒入3公斤的桶**。这时，5公斤的桶里剩下2公斤的水（因为3公斤的桶满了），3公斤的桶里有3公斤的水。
    b5.size_ -= b3.capacity_;
    b3.size_ += b3.capacity_;
    // 3. **将3公斤桶里的水倒掉**。现在，5公斤的桶里有2公斤的水，3公斤的桶是空的。
    b3.size_ = 0;
    // 4. **将5公斤桶里剩下的2公斤水倒入3公斤的桶**。现在，5公斤的桶是空的，3公斤的桶里有2公斤的水。
    b3.size_ = b5.size_;
    b5.size_ = 0;
    // 5. **将5公斤的桶再次装满**。现在，5公斤的桶里有5公斤的水，3公斤的桶里有2公斤的水。
    b5.size_ += b5.capacity_;
    // 6. **将5公斤桶里的水倒入3公斤的桶，直到3公斤的桶满为止**。这时，3公斤的桶里有3公斤的水（原来的2公斤水加上从5公斤桶倒入的1公斤水），5公斤的桶里剩下4公斤的水。
    b5.size_ -= b3.capacity_ - b3.size_;
    b3.size_ = b3.capacity_;
    
    cout << b5.size_ << endl;
    
    return 0;
}