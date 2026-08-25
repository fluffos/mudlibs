#ifndef l_roommaker_h
#define l_roommaker_h

protected void create();
void eventAbort();
varargs mixed eventCreateRoom(string file, string climate);
protected void eventPrintTitle(string title);
protected void MainMenu();
protected void MainMenuCommand(string str);
protected void ClimateMenu();
protected void ClimateMenuCommand(string cmd);
protected void TownMenu();
protected void TownMenuCommand(string cmd);
protected void PropertiesMenu();
protected void PropertiesMenuCommand(string cmd, string *props);
protected void ShortMenu();
protected void ShortMenuCommand(string str);
protected void LongMenu();
protected void LongMenuCommand(string cmd);
protected void InventoryMenu();
protected void InventoryMenuCommand(string cmd, string *items);
protected void ItemsMenu();
protected void ItemsMenuCommand(string cmd, string *items);
void CompleteItem(string *items);
protected void PropertiesMenu();
protected void PropertiesMenuCommand(string cmd, string *props);
protected void DirsMenu(string type);
protected void DirsMenuCommand(string cmd, string type, string *sorties);
protected void ObviousExitsMenu();
protected void ObviousExitsMenuCommand(string cmd);
protected void SaveRoom();

varargs nosave string GetValue(mixed val, string str);

#endif /* l_roommaker_h */
