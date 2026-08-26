
#include <creator.h>
#include <soul.h>

inherit COMMAND_BASE;

/** @ignore yes */
protected int do_update( object *ov ) {
    string pname;
    object *invent, rsv, env, dup, loaded, ob;
    mixed static_arg, dynamic_arg;

    rsv = load_object("room/void");  // RSV = Room Slash Void.
    if( !rsv )
        return notify_fail("The void is lost!\n");

    foreach( ob in ov ) {
        if( !ob )
            continue;

        if( interactive(ob) ) {
            write("Failed to update an interactive object: "+
                CAP(ob->query_name())+"\n");
            continue;
        }

        env = ENV(ob);

        invent = filter( INV(ob), (: userp($1) :) );
        invent->move(rsv);

        if( ob->query_property("npc") )
            INV(ob)->dest_me();

        pname = file_name(ob);

         // A master copy.
        if( sscanf( pname, "%s#%*d", pname ) != 2 ) {
            static_arg = ob->query_static_auto_load();
            dynamic_arg = ob->query_dynamic_auto_load();

            ob->dest_me();
            if( ob )
                ob->dwep();
            if( ob )
                destruct(ob);
            if( ob )
                return notify_fail("Failed to destruct the old object.\n");

            ob = load_object(pname);
            if( static_arg )
                ob->init_static_arg(static_arg);
            if( dynamic_arg )
                ob->init_dynamic_arg(dynamic_arg);

        } else {
            loaded = find_object(pname);
            static_arg = ob->query_static_auto_load();
            dynamic_arg = ob->query_dynamic_auto_load();

            if( loaded )
                loaded->dest_me();
            if( loaded )
                loaded->dwep();
            if( loaded )
                destruct(loaded);

            dup = clone_object(pname);
            if( dup && ob ) {
                ob->dest_me();
                if( ob )
                    ob->dwep();
                if( ob )
                    destruct(ob);
                ob = dup;
                if( static_arg )
                    ob->init_static_arg(static_arg);
                if( dynamic_arg )
                    ob->init_dynamic_arg(dynamic_arg);
            }
        }

        if( !ob ) {
            printf("I seem to have lost your object.\n");
            return 1;
        }

        invent->move(ob);

        if( env ) {
            if( ob->move(env) ) {
                if( ENV(TP) && env != ENV(TP) ) {
                    ob->move( ENV(TP) );
                    write( sprintf("Failed to move %s to %s, moving to %s.\n",
                        WIZ_PRESENT->desc_f_object( ob ),
                        WIZ_PRESENT->desc_f_object( env ),
                        WIZ_PRESENT->desc_f_object( ENV(TP) ) ) );
                } else {
                    write( sprintf("Failed to move %s to %s.\n",
                        WIZ_PRESENT->desc_f_object( ob ),
                        WIZ_PRESENT->desc_f_object( env ) ) );
                }
            }
        }

        write( sprintf("Updated %s.\n", WIZ_PRESENT->desc_f_object(ob) ) );

    }

    return 1;

} /* do_update() */

/** @ignore yes */
int cmd( string str ) {
    string tring, *filenames, err;
    object ob, *val, *obs;

    notify_fail("No such object.\n");
    tring = str;

    if( !str || str == "here") {
        str = file_name( ENV(TP) );

        if( str == "/room/void")
            return notify_fail("The Surgeon General warns you that it is "
                   "hazardous to update the void while standing in it.\n");

        str = base_name(str);
        filenames = ({"/" + str });
        str = "here";
    } else {
        filenames = TP->get_cfiles(str);
    }

    if( !sizeof(filenames) ) {
        val = WIZ_PRESENT->wiz_present( tring, TP );
        if( !sizeof(val) )
            return notify_fail("No matching objects/filenames.\n");
        return do_update(val);
    }

    obs = ({ });

    foreach( str in filenames ) {
        ob = find_object(str);
        if( !ob ) {
            if( file_exists(str) ) {
                if( sscanf( str, SOUL_DIR+"%s", err ) == 1 ) {
                    err = catch( SOUL_COMPILER->compile_file("/"+err ) );
                    if( err )
                        printf("Failed to load %s, error: %s\n", str, err );
                    else
                        printf("Loaded %s (soul).\n", str );
                } else {
                    err = catch( ob = load_object(str) );
                    if( err )
                        printf("Failed to load %s, error: %s\n", str, err );
                    else if( !ob )
                        printf( str+" cannot be compiled.\n");
                    else
                        printf("Loaded %s\n", str );
                }
            } else {
                val = WIZ_PRESENT->wiz_present( tring, TP );
                obs += val;
            }
        } else {
            obs += ({ ob });
        }
    }

    if( !obs )
        return 0;

    return do_update(obs);

} /* cmd() */
