#define SF_DIR   "/realms/melchezidek/projects/starfire/"
#define SF_NPC   SF_DIR "npc/"
#define SF_OBJ   SF_DIR "obj/"
#define SF_ROOM  SF_DIR "room/"
#define SF_ROOM_EXIT "/realms/melchezidek/workroom.lpc"

int BlowUp() {
  if (this_object()->GetShort() == "the room of immolation") {
    SF_ROOM "room07"->eventPrint("A loud boom echoes throughout"
      "the room as the exit south is slammed shut.");
    return 1;
  }
  return 0;
}
