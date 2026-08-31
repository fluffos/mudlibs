#include <daemons.h>
#include <gmcp_defines.h>

inherit __DIR__ "gmcp_module";

void Login(string submodule, mapping data) {
  if(!data)
    return;

  object login = previous_object();

  switch(submodule) {
    case "Credentials" : {
      string username, account_name, password, character, curr, test;
      mapping account;

      if(!data["account"])
        return;

      username = lower_case(data["account"]);
      sscanf(username, "%s@%s", character, account_name);

      account = ACCOUNT_D->load_account(account_name);
      password = data["password"];

      if(!account || !account["password"]) {
        GMCP_D->send_gmcp(login,
          GMCP_PKG_CHAR_LOGIN_RESULT,
          ([ "success" : "false", "message": "Invalid account name."])
        );

        tell(login, "Invalid account name.\n");
        login->remove();
        return;
      }

      curr = account["password"];
      test = crypt(password, curr);
      if(test != curr) {
        GMCP_D->send_gmcp(login,
          GMCP_PKG_CHAR_LOGIN_RESULT,
          ([ "success" : "false", "message": "Invalid password."])
        );
        tell(login, "Invalid password.\n");
        login->remove();
        return;
      }

      GMCP_D->send_gmcp(login,
        GMCP_PKG_CHAR_LOGIN_RESULT,
        ([ "success" : "true", "message": "Login successful."])
      );

      login->gmcp_authenticated(username, character);
    }
  }
}

void Items(string submodule, string target) {
  object player = previous_object();

  switch(submodule) {
    case "Contents" :
      GMCP_D->send_gmcp(player, GMCP_PKG_CHAR_ITEMS_LIST, target);
      break;
    case "Inv" :
      GMCP_D->send_gmcp(player, GMCP_PKG_CHAR_ITEMS_LIST, GMCP_LIST_INV);
      break;
    case "Room" :
      GMCP_D->send_gmcp(player, GMCP_PKG_CHAR_ITEMS_LIST, GMCP_LIST_ROOM);
      break;
  }
}
