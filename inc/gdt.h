#ifndef GDT
#define GDT
#include <stdint.h>

typedef struct gdt_entry
{
    uint16_t        limit_0;
    uint16_t        base_0;
    uint8_t         base_1;
    uint8_t         access_byte;
    uint8_t         limit1_f;
    uint8_t         base_2;
} __attribute__((packed)) _gdt_entry;

typedef struct gdt_desc
{
    uint16_t        size;
    uint64_t        offset;
} __attribute__((packed)) _gdt_desc;

typedef struct gdt_general
{
    _gdt_entry entries[6];
} __attribute__((packed));

void init_gdt();
void load_gdt(_gdt_desc *desc);

#endif