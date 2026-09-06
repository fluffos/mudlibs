#define F_ENTITY_RESET_USED        1
#define F_ENTITY_INIT_USED         2

private nosave int flags;
private nosave int lumens;
private string name;
private string * aliases;
private mixed brief;
private mixed description;

int
query_lumens()
{
    return lumens;
}

void
set_lumens(int arg)
{
    lumens = arg;
}

string
query_name()
{
    return name;
}

void
set_name(string arg)
{
    name = arg;
}

string *
query_aliases()
{
    return pointerp(aliases) ? copy(aliases) : 0;
}

void
set_aliases(string * arg)
{
    if (!arg) {
	aliases = 0;
	return;
    }

    if (pointerp(arg)) {
	aliases = copy(arg);
    }
}

void
add_alias(string arg)
{
    if (!arg) {
	return;
    }

    if (!pointerp(aliases)) {
	aliases = ({ arg });
	return;
    }

    if (member(aliases, arg) < 0) {
	aliases += ({ arg });
    }
}

void
remove_alias(string arg)
{
    if (arg && aliases && pointerp(aliases)) {
	aliases -= ({ arg });
    }
}

int
has_alias(string arg)
{
    if (!arg || !pointerp(aliases)) {
	return 0;
    }

    return member(aliases, arg) >= 0 ? 1 : 0;
}

string
query_brief()
{
    if (closurep(brief)) {
        return funcall(brief);
    }

    return brief;
}

void
set_brief(mixed arg)
{
    if (!stringp(arg) || !closurep(arg)) {
        return;
    }

    brief = arg;
}

string
query_description()
{
    if (closurep(description)) {
        return funcall(description);
    }

    return description;
}

void
set_description(mixed arg)
{
    if (!stringp(arg) || !closurep(arg)) {
        return;
    }

    description = arg;
}

int
id(string arg)
{
    if (!arg || !name) {
	return 0;
    }

    if (arg == name) {
	return 1;
    }

    return has_alias(arg);
}

void
create()
{
    if (function_exists("reset_entity", this_object())) {
	flags |= F_ENTITY_RESET_USED;
    }

    this_object()->create_room();

    if (function_exists("init_entity", this_object())) {
	flags |= F_ENTITY_INIT_USED;
    }
}

void
reset()
{
    if (flags & F_ENTITY_RESET_USED) {
	this_object()->reset_entity();
    }

    // reset_entity() may call destruct()
    if (!this_object()) {
       return;
    }
}

void
init()
{
    if (flags & F_ENTITY_INIT_USED) {
	this_object()->init_entity();
    }

    if (!this_player()) {
	return;
    }
}
