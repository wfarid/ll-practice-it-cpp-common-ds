/*
 * When I started this file `bitfields.c`, I was thinking about a way
 * to use bitfields to solve this problem of sending 11 bytes instead of
 * 84 bytes (where 1 byte represent 1 bit) over UART in order to send
 * less bytes at a lower baudrate of 115,200 bps instead of 460,800 bps.
 * I was trying to avoid the solution below, and utilize bitfields for a
 * more elegant solution, but I ended up using the solution below with the
 * packed byte array.
 */
#include <stdio.h>

// typedef struct sTypeTag
// {
//   unsigned char x : 1;
// } sType;

// int main(void)
// {
//   printf("%s\r\n", __FILE__);
//   printf("sizeof(sType): %d\r\n bytes", sizeof(sType));
//   // printf("sizeof(struct ): %d\r\n", sizeof(sType));
// }

#include <stdio.h>
#include <string.h>

#define NUM_BITS 81
#define NUM_BYTES ((NUM_BITS + 7) / 8) // 11 bytes for 81 bits

int main(void)
{
  printf("%s\r\n", __FILE__);

  // Original: 84 bytes, each holding 0 or 1
  unsigned char original[NUM_BITS];
  for (int i = 0; i < NUM_BITS; i++)
    original[i] = (i % 2); // Example: alternating 0s and 1s

  // Optimized: Pack into 11 bytes
  unsigned char packed[NUM_BYTES] = {0};

  // Pack bits into bytes
  for (int i = 0; i < NUM_BITS; i++)
  {
    if (original[i])
      packed[i / 8] |= (1 << (i % 8)); // Set bit
  }

  printf("Original size: %d bytes\r\n", NUM_BITS);
  printf("Packed size: %d bytes\r\n", NUM_BYTES);
  printf("Space saved: %.1f%%\r\n", (1.0 - NUM_BYTES / (float)NUM_BITS) * 100);

  // Send packed bytes via UART (example)
  printf("Packed data: ");
  for (int i = 0; i < NUM_BYTES; i++)
    printf("%02X ", packed[i]);
  printf("\r\n");

  return 0;
}