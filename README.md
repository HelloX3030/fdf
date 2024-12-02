# todo 
- Fix Makefile
- Leaks?
- Fix Pyra.fdf
	=> Wrong Map Heigth

- Optimization:
	- Data Oriented Design
	- Profilers
	- compiler flags:
		- int var __attribute__((aligned(16))); // Aligns var to a 16-byte boundary.
		- struct __attribute__((packed)) MyStruct {
    char a;
    int b;
}; // No padding added.
void compute() __attribute__((hot));
/ cold 
- void* my_alloc(size_t size) __attribute__((malloc));
- if (__builtin_expect(x == 0, 0)) { /* unlikely case */ }
- __builtin_prefetch(array + i);
- int count = __builtin_popcount(42);
- if (some_condition) { /* handle */ }
- __builtin_unreachable(); // No code can reach here.
- Recursion: generally better: char ** list things, to reduce overhead for memory usage 
- Don't use function ptr, try to keep flow of the application as linear as possible (no ifs...)
- use inline 
- for (int i = 0; i < n; i++) {
    __builtin_prefetch(&array[i+1]);
    process(array[i]);
}
- avoid if statements:
	- mathematical trics like:
	- if (x > 0) {
    result = 1;
} else {
    result = -1;
}
better:
result = (x > 0) * 2 - 1;
or:
const int results[] = { -1, 1 }; // lookup table
result = results[x > 0];        // no branching
Loop unroling:
for (int i = 0; i < n; i += 4) {
    array[i] = array[i] * 2;
    array[i+1] = array[i+1] * 2;
    array[i+2] = array[i+2] * 2;
    array[i+3] = array[i+3] * 2;
}
dereferencing:
for (int i = 0; i < n; i++) {
    // Costly dereference inside loop
    result += *(arr + i);
}

// Optimize by storing dereferenced value in a local variable
int *p = arr;
for (int i = 0; i < n; i++) {
    result += *(p + i);
}

struct Data {
    char a;  // 1 byte
    int b;   // 4 bytes
    // Without padding, `b` could be misaligned.
} __attribute__((aligned(16)));  // Ensure 16-byte alignment
gcc -O3 -ftree-vectorize -march=native

