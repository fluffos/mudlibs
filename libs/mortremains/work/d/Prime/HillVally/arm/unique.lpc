// Unique.c
// A unique object. Coded as an example by Cyanide.
// 17 Jun 98

// This number is the number of these allowed on the mud.
#define NUMBER_ALLOWED 1

inherit OBJECT;

void output();

void create() {
    int num;  

    // This is the important bit.
    num = NUMBER_ALLOWED + 1;
    if (sizeof(children(base_name(TO))) > num) return;

    set("author", "cyanide");
    set("short", "a thing");
    set("long", "Yup. Its definitely a thing.\n");
    set("id", ({ "thing", }) );
}

// End of File
