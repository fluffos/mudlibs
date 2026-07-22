// place.h for tdh_job target_npc
// Creat by Lklv at 2002.1.19

string *no_kill_list = ({
	 "mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int check(object target)
{
	object room;
	string room_name;

	if(!objectp(target)
	 || !target->query("startroom")
	 || target->query("env/invisibility")
	 || target->query("no_quest")
	 || member_array(target->query("id"), no_kill_list) != -1
	 || userp(target)
	 || target->query("attitude")=="aggressive"
	 || target->query("have_master")
	 || !objectp(room=environment(target))
	 || room->query("no_fight")
	 || room->query("outdoors") == "昆仑翠谷"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/wudang/") == 0
	 || strsrch(room_name, "/d/meizhuang/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}
