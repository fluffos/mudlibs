// FluffOS PORT: input_to() flags. LDMud's INPUT_NOECHO maps directly onto
// this driver's native I_NOECHO bit. LDMud's INPUT_IGNORE_BANG (suppress
// the "!" input_to-cancel convention) has no FluffOS equivalent -- this
// driver has no such cancel convention to suppress in the first place, so
// it's defined as an inert 0 bit (safely OR-able into flags, no effect).
#define INPUT_NOECHO      1
#define INPUT_IGNORE_BANG 0
