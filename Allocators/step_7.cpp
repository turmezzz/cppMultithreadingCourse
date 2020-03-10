#include <stdlib.h>

// do not fucking understand what they want me to do in this task

class SmallAllocator {
public:
    void* Alloc(unsigned int Size) {
        return malloc(Size);
    };

    void* ReAlloc(void* Pointer, unsigned int Size) {
        void* new_data = malloc(Size);

        char* it = (char*)Pointer;
        char* new_it = (char*)new_data;

        for (int i = 0; i < Size; ++i) {
            *(new_it++) = *(it++);
        }

        return new_data;
    };

    void Free(void* Pointer) {
        return free(Pointer);
    };
};

int main(int argc, char** argv) {
    
    return 0;
}