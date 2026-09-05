/* object access */
#ifndef __LDMUD__
#ifndef private
#endif
#define private if (this_player() != this_object()) return 0
#endif

