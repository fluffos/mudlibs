// petd.c
//
// by meteor

#include <ansi.h>

void create() { seteuid(getuid()); }

string create_pet(object user)
{
        object pet, *pets;

        pets = children(PET_OB);
        for( int i=0; i < sizeof(pets); i++ ) {
                if( pets[i]->query("owner_id") == user->query("id") ) {
                        user->set_temp("created_pet", pets[i]);
                        return "你的宠物正在等着你呢，快去找它呀！\n\n";
                }
        }
        
        if( !(pet = new(PET_OB)) )
                return HIY "你觉得好象失落了什么重要的东西，赶快通知巫师吧！\n\n" NOR;
                
        pet->setup_pet(user->query("id"));
        if( !pet->restore() ) {
                destruct(pet);
                return HIY "你觉得好象失落了什么重要的东西，赶快通知巫师吧！\n\n" NOR;
        }
        if( pet->query("died") ) {
                if( (int)user->query("pet_died") ) {
                        if( (int)user->query("pet_died") < 86400 ) {
                                destruct(pet);
                                return HIY "你的宠物还没有复活，再耐心等等吧！\n\n" NOR;
                        }
                        else {
                                user->delete("pet_died");
                                pet->delete("died");
                                user->save();
                                pet->save();
                        }
                }
                else {
                        user->set("pet_died", 1);
                        destruct(pet);
                        return HIY "你的宠物还没有复活，再耐心等等吧！\n\n" NOR;
                }
        }
        seteuid(pet->query("id"));
        export_uid(pet);
        seteuid(getuid());
        pet->setup();
        pet->set_name(pet->name(), ({ pet->query("id") }));
        if( !pet->move(environment(user)) ) {
                destruct(pet);
                return HIY "你觉得好象失落了什么重要的东西，赶快通知巫师吧！\n\n" NOR;
        }
        user->set_temp("created_pet", pet);
        return "Pet loaded.\n\n";
}
