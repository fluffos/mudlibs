#ifndef l_roommaker_h
#define l_roommaker_h

nosave void create();
void eventAbort();
varargs mixed eventCreateRoom(string file, string climate);
nosave void eventPrintTitle(string title);
nosave void MainMenu();
nosave void MainMenuCommand(string str);
nosave void ClimateMenu();
nosave void ClimateMenuCommand(string cmd);
nosave void TownMenu();
nosave void TownMenuCommand(string cmd);
nosave void PropertiesMenu();
nosave void PropertiesMenuCommand(string cmd, string *props);
nosave void ShortMenu();
nosave void ShortMenuCommand(string str);
nosave void LongMenu();
nosave void LongMenuCommand(string cmd);
nosave void InventoryMenu();
nosave void InventoryMenuCommand(string cmd, string *items);
nosave void ItemsMenu();
nosave void ItemsMenuCommand(string cmd, string *items);
void CompleteItem(string *items);
nosave void PropertiesMenu();
nosave void PropertiesMenuCommand(string cmd, string *props);
nosave void DirsMenu(string type);
nosave void DirsMenuCommand(string cmd, string type, string *sorties);
nosave void ObviousExitsMenu();
nosave void ObviousExitsMenuCommand(string cmd);
nosave void SaveRoom();

varargs nosave string GetValue(mixed val, string str);

#endif /* l_roommaker_h */
