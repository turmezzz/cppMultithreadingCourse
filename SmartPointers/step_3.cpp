#include <iostream>

class StringPointer {
private:
    std::string* data;
    bool wasAllocated = false;
public:
    std::string* operator->() {
        return data;
    }
    std::string operator*() {
        if (!data) {
            wasAllocated = true;
            data = new std::string();
        }
        return *data;
    }
    StringPointer(std::string* Pointer) {
        data = Pointer;
    }
    ~StringPointer() {
        if (wasAllocated) {
            delete data;
        }
    }
};

int main() {
    return 0;
}