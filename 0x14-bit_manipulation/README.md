# Bit Manipulation Tasks

This Directory contains C functions for various bit manipulation tasks.

## Task Descriptions

1. **binary_to_uint**

   - Prototype: `unsigned int binary_to_uint(const char *b);`
   - Converts a binary number represented as a string to an unsigned integer.

2. **print_binary**

   - Prototype: `void print_binary(unsigned long int n);`
   - Prints the binary representation of a number.

3. **get_bit**

   - Prototype: `int get_bit(unsigned long int n, unsigned int index);`
   - Returns the value of a bit at a given index.

4. **set_bit**

   - Prototype: `int set_bit(unsigned long int *n, unsigned int index);`
   - Sets the value of a bit to 1 at a given index.

5. **clear_bit**

   - Prototype: `int clear_bit(unsigned long int *n, unsigned int index);`
   - Sets the value of a bit to 0 at a given index.

6. **flip_bits**

   - Prototype: `unsigned int flip_bits(unsigned long int n, unsigned long int m);`
   - Returns the number of bits needed to flip to get from one number to another.

7. **get_endianness**

   - Prototype: `int get_endianness(void);`
   - Checks the endianness of the system (big or little endian)
