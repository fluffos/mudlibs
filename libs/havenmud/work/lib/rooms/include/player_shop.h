/*  Player Shop .h file
 */
string SetOwner(string);
string GetOwner();
string SetCurrentBidder(string);
string GetCurrentBidder();
mixed SetKiller(mixed);
nosave void LoadInventory();
mixed GetKiller();
mapping SetSaleInventory(mapping);
mapping GetSaleInventory();
mapping AddSaleInventory(string, int, string);
mapping RemoveSaleInventory(string);
int SetSaleCost(string, int);
int AddSaleCost(string, int);
int GetSaleCost(string);
int SetInnkeep(int);
int GetInnkeep();
int SetMeatCost(string, int);
int GetMeatCost(string);
int SetMad(int);
int GetMad();
int AddMad(int);
int SetCurrentBid(int);
int GetCurrentBid();
int SetStoreFunds(int);
int GetStoreFunds();
int AddStoreFunds(int);
int SetMeatPoints(int);
int AddMeatPoints(int);
int GetMeatPoints();
int SetMeat(string, int);
int AddMeat(string, int);
int GetMeat(string);
string SetShopId(string);
string GetShopId();
string SetLocalCurrency(string);
string GetLocalCurrency();
string SetShopName(string);
string GetShopName();
string SetShopDesc(string);
string GetShopDesc();
int SetPayOut(string, int);
int RemovePayOut(string);
int GetPayOut(string);
mapping GetShopInfo();
mapping GetPayOuts();
void ChooseInvOption(string);
void ChooseMakeOption(string);
void ChoosePriceOption(string);
void ChooseFundsOption(string);
void ChooseSetupOption(string);
void AddInvItem(string);
void RemoveInvItem(string);
void MakeFood(string);
void DoPrice(string, string);
void DoSalePrice(string, string);
void MakeInnkeeper();
void SetupShopName(string);
void SetupShopDesc(string);
void DepositFunds(string);
void WithdrawFunds(string);
void ChooseAmount(string, string);

mapping Towns = ([
  "Argoth": "orc",
  "Baria": "human",
  "Glimmerdin": "dwarf",
  "Grymxoria": "nosferatu",
  "Haven": "elf",
  "Heyam": "gnoll",
  "the HavenWood": "gelfling",
  "Jidoor": "sprite",
  "Keryth": "human",
  "Kresh": "goblin",
  "Lloryk": "halfling",
  "Soleil": "muezzin",
  "Ungkh": "ogre",
  "Yozrath": "human",
  "Wilderness": "elf",
  "Malveillant": "dark-elf",
]);

mapping Languages = ([
  "Argoth": "Uruk",
  "Baria": "Barian",
  "Durgoroth": "Blaodric",
  "Glimmerdin": "Runic",
  "Grymxoria": "Blaodric",
  "Haven": "Eltherian",
  "Heyam": "Heyami",
  "the HavenWood": "Eltherian",
  "Jidoor": "Sprith",
  "Keryth": "Drakem",
  "Kresh": "Gobyshkin",
  "Lloryk": "Eltherian",
  "Soleil": "Oiseau",
  "Ungkh": "Shangtai",
  "Yozrath": "Padashi",
  "Wilderness": "Eltherian",
  "Malveillant": "Eltherian",
]);
