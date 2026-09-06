#include <container.h>

int volume;

void
create_container()
{
    volume=random(5);
    set_max_weight(6+volume);
    set_weight(1);
    set_name("bag");
    set_short("A "+({ "","large ","huge " })[volume/2]+"bag");
    set_long("A "+({ "","large ","huge " })[volume/2]+"bag.");
    set_value(12+volume*2);
}
