// file: /adm/simul_efun/override.c
// to override some driver efun
// Swinger (May 1, 97)  -       created this file
//                      -       add snoop()

nomask varargs object snoop(object snooper, object snoopee) {
        if(!snoopee) return efun::snoop(snooper);
        if(!wizardp(snooper))   return 0;
       if(SECURITY_D->get_wiz_level(snooper)
          <= SECURITY_D->get_wiz_level(snoopee) &&
          SECURITY_D->get_status(snooper) != "(manager)" &&
          SECURITY_D->get_status(snooper) != "(guest)" &&
          SECURITY_D->get_status(snooper) != "(admin)" &&
          SECURITY_D->get_status(snooper) != "(arch)"  &&
          SECURITY_D->get_status(snooper) != "(wizard)")
                return 0; 
         if( wizhood(snooper) != "(manager)"
            &&  wizhood(snooper) != "(admin)"
            &&  wizhood(snooper) != "(guest)"
            &&  wizhood(snooper) != "(arch)"  
            &&  wizhood(snooper) != "(wizard)"
            ) return 0;
                       
        return efun::snoop(snooper, snoopee);
}