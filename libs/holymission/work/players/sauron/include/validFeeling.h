#include "/players/sauron/include/adverbs.h"
#include "/players/sauron/include/feelings.h"
#include "/players/sauron/include/listArray.h"

mapping mFeelings,mAdverbs;

string substitute(string sStr,string sMatch,string sRep) {
    if(sStr && sMatch && sRep)
        return implode(explode(sStr,sMatch),sRep);
}

string pluraliseVerb(string sVerb) {
    return lower_case("/players/sauron/daemon/inventoryd"->pluralise(sVerb));
}

void initAdverbs() {
    if(!mAdverbs) {
        mAdverbs=([]);
        mAdverbs['a']=ADVERBS_A;
        mAdverbs['b']=ADVERBS_B;
        mAdverbs['c']=ADVERBS_C;
        mAdverbs['d']=ADVERBS_D;
        mAdverbs['e']=ADVERBS_E;
        mAdverbs['f']=ADVERBS_F;
        mAdverbs['g']=ADVERBS_G;
        mAdverbs['h']=ADVERBS_H;
        mAdverbs['i']=ADVERBS_I;
        mAdverbs['j']=ADVERBS_J;
        mAdverbs['k']=ADVERBS_K;
        mAdverbs['l']=ADVERBS_L;
        mAdverbs['m']=ADVERBS_M;
        mAdverbs['n']=ADVERBS_N;
        mAdverbs['o']=ADVERBS_O;
        mAdverbs['p']=ADVERBS_P;
        mAdverbs['q']=ADVERBS_Q;
        mAdverbs['r']=ADVERBS_R;
        mAdverbs['s']=ADVERBS_S;
        mAdverbs['t']=ADVERBS_T;
        mAdverbs['u']=ADVERBS_U;
        mAdverbs['v']=ADVERBS_V;
        mAdverbs['w']=ADVERBS_W;
        mAdverbs['x']=ADVERBS_X;
        mAdverbs['y']=ADVERBS_Y;
        mAdverbs['z']=ADVERBS_Z;
    }
}

void initFeelings() {
    if(!mFeelings) {
        mFeelings=([]);
        mFeelings+=FEELINGS_A;
        mFeelings+=FEELINGS_B;
        mFeelings+=FEELINGS_C;
        mFeelings+=FEELINGS_D;
        mFeelings+=FEELINGS_E;
        mFeelings+=FEELINGS_F;
        mFeelings+=FEELINGS_G;
        mFeelings+=FEELINGS_H;
        mFeelings+=FEELINGS_I;
        mFeelings+=FEELINGS_J;
        mFeelings+=FEELINGS_K;
        mFeelings+=FEELINGS_L;
        mFeelings+=FEELINGS_M;
        mFeelings+=FEELINGS_N;
        mFeelings+=FEELINGS_O;
        mFeelings+=FEELINGS_P;
        mFeelings+=FEELINGS_Q;
        mFeelings+=FEELINGS_R;
        mFeelings+=FEELINGS_S;
        mFeelings+=FEELINGS_T;
        mFeelings+=FEELINGS_U;
        mFeelings+=FEELINGS_V;
        mFeelings+=FEELINGS_W;
        mFeelings+=FEELINGS_X;
        mFeelings+=FEELINGS_Y;
        mFeelings+=FEELINGS_Z;
    }
}

varargs string *allAdverbs(string sStr) {
    string *saTmp;

    initAdverbs();
    if(sStr && sStr!="")
        return m_indices(mAdverbs[sStr[0]]);
    else {
        saTmp=({});
        saTmp+=mAdverbs['a'];
        saTmp+=mAdverbs['b'];
        saTmp+=mAdverbs['c'];
        saTmp+=mAdverbs['d'];
        saTmp+=mAdverbs['e'];
        saTmp+=mAdverbs['f'];
        saTmp+=mAdverbs['g'];
        saTmp+=mAdverbs['h'];
        saTmp+=mAdverbs['i'];
        saTmp+=mAdverbs['j'];
        saTmp+=mAdverbs['k'];
        saTmp+=mAdverbs['l'];
        saTmp+=mAdverbs['m'];
        saTmp+=mAdverbs['n'];
        saTmp+=mAdverbs['o'];
        saTmp+=mAdverbs['p'];
        saTmp+=mAdverbs['q'];
        saTmp+=mAdverbs['r'];
        saTmp+=mAdverbs['s'];
        saTmp+=mAdverbs['t'];
        saTmp+=mAdverbs['u'];
        saTmp+=mAdverbs['v'];
        saTmp+=mAdverbs['w'];
        saTmp+=mAdverbs['x'];
        saTmp+=mAdverbs['y'];
        saTmp+=mAdverbs['z'];
        return saTmp;
    }
}

string *allFeelings() {
    initFeelings();
    return m_indices(mFeelings);
}

string validAdverb(string sMatch) {
    string *saAdverbs,*saTmp;
    int i,iLen,iSz;

    initAdverbs();
    if(!sMatch || sMatch=="")
        return 0;
    else
        iLen=strlen(sMatch)-1;
    saAdverbs=mAdverbs[sMatch[0]];
    saTmp=({});
    i=0;
    iSz=sizeof(saAdverbs);
    for(i=0;i<iSz;i++) {
        if(saAdverbs[i][0..iLen]==sMatch)
            saTmp+=({saAdverbs[i]});
    }
    if(sizeof(saTmp)==1)
        return saTmp[0];
    else if(sizeof(saTmp))
        printf("The adverb \"%s\" is ambiguous (\"%s\"). Please be more \
precise.\n",
               sMatch,listArray(saTmp,1));
    else
        printf("No adverb found to match '%s'.\n",sMatch);
}

varargs mixed validFeeling(string sMatch,int iFlag) {
    string *saFeelings,*saTmp;
    int i,iLen,iSz;

    initFeelings();
    saFeelings=m_indices(mFeelings);
    if(!sMatch || sMatch=="")
        return 0;
    else
        iLen=strlen(sMatch)-1;
    saTmp=({});
    i=0;
    iSz=sizeof(saFeelings);
    for(i=0;i<iSz;i++) {
        if(saFeelings[i][0..iLen]==sMatch)
            saTmp+=({saFeelings[i]});
    }
    if(iFlag)
        return saTmp;
    else if(sizeof(saTmp)==1)
        return saTmp[0];
    else if(sizeof(saTmp))
        printf("The feeling \"%s\" is ambiguous (\"%s\"). Please be more \
precise.\n",
               sMatch,listArray(saTmp,1));
//    else
//        printf("No feeling found to match '%s'.\n",sMatch);
}

string validRemoteFeeling(string sMatch) {
    string *saTmp;
    if(sMatch && sMatch!="" && sMatch[0..0]=="r") {
        saTmp=validFeeling(sMatch[1..<1],1);
        if(sizeof(saTmp)==1)
            return "r"+saTmp[0];
        else if(sizeof(saTmp))
            printf("The remote feeling \"%s\" is ambiguous (\"%s\"). Please \
be more precise.\n",
                   sMatch,listArray(saTmp,1));
        else
            printf("No remote feeling found to match '%s'.\n",sMatch);
    }
}

varargs string *parseFeeling(string sVerb,object oTarget,string sAdverb,
                             int iRemote) {
    string *saRet,*saTmp,sTmp,sRet;
    object oSubject;

    oSubject=this_player();
    saRet=allocate(3);
    if(sVerb) {
        saTmp=mFeelings[sVerb];
        if(oTarget) {
            sRet=saTmp[TARGET];
            if(!sRet) {
                sRet=saTmp[SIMPLE];
                oTarget=(object)0;
            }
        }
        else {
            sRet=saTmp[SIMPLE];
            if(!sRet) {
                printf("The feeling '%s%s' requires a target.\n",
                       iRemote==1?"r":"",sVerb);
                return saRet;
            }
        }
        if(!sAdverb && saTmp[ADVERB])
            sAdverb=saTmp[ADVERB];

        saRet[0]=sRet;
        if(iRemote==1)
            saRet[0]=substitute(saRet[0],"$Ns","you");
        else
            saRet[0]=substitute(saRet[0],"$Ns","You");
        saRet[0]=substitute(saRet[0],"$Ps","your");
        if(oTarget) {
            if(oTarget==oSubject) {
                saRet[0]=substitute(saRet[0],"$Nv","yourself");
                saRet[0]=substitute(saRet[0],"$Pv","your own");
            }
            else {
                sTmp=oTarget->query_name();
                saRet[0]=substitute(saRet[0],"$Nv",sTmp);
                saRet[0]=substitute(saRet[0],"$Pv",sTmp+(sTmp[<1..<1]=="s"?
                                                             "'":
                                                             "'s"));
            }
        }
        saRet[0]=substitute(saRet[0],"$V",sVerb);
        if(sAdverb)
            saRet[0]=substitute(saRet[0],"$A",sAdverb);
            
        if(oTarget && oTarget!=oSubject) {
            saRet[1]=sRet;
            if(oSubject->is_invis_for(oTarget))
                saRet[1]=substitute(saRet[1],"$Ns","Someone");
            else
                saRet[1]=substitute(saRet[1],"$Ns",oSubject->query_name_true());
            saRet[1]=substitute(saRet[1],"$Ps",oSubject->query_possessive());
            saRet[1]=substitute(saRet[1],"$Nv","you");
            saRet[1]=substitute(saRet[1],"$Pv","your");
            saRet[1]=substitute(saRet[1],"$V",pluraliseVerb(sVerb));
            if(sAdverb)
                saRet[1]=substitute(saRet[1],"$A",sAdverb);
        }

        if(iRemote!=1) {
            saRet[2]=sRet;
            saRet[2]=substitute(saRet[2],"$Ns",oSubject->query_name());
            saRet[2]=substitute(saRet[2],"$Ps",oSubject->query_possessive());
            if(oTarget) {
                if(oTarget==oSubject) {
                    saRet[2]=substitute(saRet[2],"$Nv",
                                        oSubject->query_objective()+"self");
                    saRet[2]=substitute(saRet[2],"$Pv",
                                        oSubject->query_possessive()+" own");
                }
                else {
                    sTmp=oTarget->query_name();
                    saRet[2]=substitute(saRet[2],"$Nv",sTmp);
                    saRet[2]=substitute(saRet[2],"$Pv",sTmp+(sTmp[<1..<1]=="s"?
                                                                 "'":
                                                                 "'s"));
                }
            }
            saRet[2]=substitute(saRet[2],"$V",pluraliseVerb(sVerb));
            if(sAdverb)
                saRet[2]=substitute(saRet[2],"$A",sAdverb);
        }

        return saRet;
    }
}

int executeFeeling(string sVerb,string sStr) {
    string *saTmp,sTmp,sTarget,sAdverb;
    int iTmp,iRemote;
    object oTarget;

    if(sStr=="")
        sStr=(string)0;
    if(sStr) {
        if(sscanf(sStr,"%s %s",sTarget,sAdverb)!=2)
            sTarget=sStr;
    }

    if((sTmp=validRemoteFeeling(sVerb))) {
        iRemote=1;
        sVerb=sTmp;
    }
    else if((sTmp=validFeeling(sVerb)))
        sVerb=sTmp;
    else
        return 0;

    printf("Parsed test string '%s%s' into the following components:\n\
%s%s%s\n",sVerb,sStr?" "+sStr:"",
(sVerb?"verb  : "+sVerb+"\n":""),
(sTarget?"target: "+sTarget+"\n":""),
(sAdverb?"adverb: "+sAdverb+"\n":""));

// This could actually be target OR adverb:
    if(sTarget) {
        if(iRemote)
            sTmp=matchName(sTarget,0);
        else
            sTmp=matchName(sTarget,2);
        if(sTmp) {
            if(iRemote)
                oTarget=find_player(sTmp);
            else
                oTarget=present(sTmp,environment(this_player()));
            printf("Target '%s' matched. Proceeding.\n",sTmp);
        }
// If no target found, assume that an adverb was intended.
        else {
            printf("Assuming that \"%s\" is an adverb not a target.\n",
                   sTarget);
            sAdverb=sTarget;
            sTarget=(string)0;
        }
    }

    if(sAdverb) {
        if((sTmp=validAdverb(sAdverb))) {
            sAdverb=sTmp;
            printf("Adverb '%s' matched. Proceeding.\n",sAdverb);
        }
        else
            return 1;
    }

    saTmp=parseFeeling(sVerb[iRemote..<1],oTarget,sAdverb,iRemote);
    if(sizeof(saTmp)!=3)
        sTmp="\nDidn't receive the expected parsed msgs!\n";
    else {
        sTmp="\nFinal parsed feeling string for '"+sVerb+"':\n";
        if(saTmp[0]) {
            sTmp+="Msg_self  : ";
            if(iRemote)
                saTmp[0]="From afar, "+saTmp[0];
            saTmp[0]+="\n";
            sTmp+=saTmp[0];
        }
        if(saTmp[1]) {
            sTmp+="Msg_target: ";
            if(iRemote)
                saTmp[1]="From afar, "+saTmp[1];
            saTmp[1]+="\n";
            sTmp+=saTmp[1];
        }
        if(saTmp[2]) {
            sTmp+="Msg_other : ";
            if(iRemote)
                saTmp[2]="From afar, "+saTmp[2];
            saTmp[2]+="\n";
            sTmp+=saTmp[2];
        }
    }
    write(sTmp+"\n");
    if(saTmp[0])
        write(saTmp[0]);
    if(saTmp[1] && oTarget)
        tell_object(oTarget,saTmp[1]);
    if(saTmp[2])
        say(saTmp[2],oTarget);
    return 1;
}

string executeChannelFeeling(string sStr,object *oaUsers) {
    string *saTmp,sTmp,sVerb,sTarget,sAdverb;
    int iTmp;
    object oTarget;

    if(sStr=="")
        sStr=(string)0;
    if(sStr) {
        iTmp=sscanf(sStr,"%s %s %s",sVerb,sTarget,sAdverb);
        if(iTmp!=3) {
            iTmp=sscanf(sStr,"%s %s",sVerb,sTarget);
            if(iTmp!=2)
                sVerb=sStr;
        }
    }

    if((sTmp=validFeeling(sVerb)))
        sVerb=sTmp;
    else
        return 0;

    printf("Parsed test string '%s%s' into the following components:\n\
%s%s%s\n",sVerb,sStr?" "+sStr:"",
(sVerb?"verb  : "+sVerb+"\n":""),
(sTarget?"target: "+sTarget+"\n":""),
(sAdverb?"adverb: "+sAdverb+"\n":""));

// This could actually be target OR adverb:
    if(sTarget) {
        sTmp=matchName(sTarget,3,oaUsers);
       if(sTmp) {
            oTarget=find_player(sTmp);
            printf("Target '%s' matched. Proceeding.\n",sTmp);
        }
// If no target found, assume that an adverb was intended.
        else {
            printf("Assuming that \"%s\" is an adverb not a target.\n",
                   sTarget);
            sAdverb=sTarget;
            sTarget=(string)0;
        }
    }

    if(sAdverb) {
        if((sTmp=validAdverb(sAdverb))) {
            sAdverb=sTmp;
            printf("Adverb '%s' matched. Proceeding.\n",sAdverb);
        }
        else
            return 0;
    }

    saTmp=parseFeeling(sVerb,oTarget,sAdverb,0);
    if(sizeof(saTmp)!=3)
        sTmp="\nDidn't receive the expected parsed msgs!\n";
    else {
        sTmp="\nFinal parsed feeling string for '"+sVerb+"':\n";
        if(saTmp[0]) {
            sTmp+="Msg_self  : ";
            saTmp[0]+="\n";
            sTmp+=saTmp[0];
        }
        if(saTmp[1]) {
            sTmp+="Msg_target: ";
            saTmp[1]+="\n";
            sTmp+=saTmp[1];
        }
        if(saTmp[2]) {
            sTmp+="Msg_other : ";
            saTmp[2]+="\n";
            sTmp+=saTmp[2];
        }
    }

    return saTmp[2];
}
