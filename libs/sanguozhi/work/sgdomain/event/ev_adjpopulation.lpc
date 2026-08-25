// ev_adjpopulation.c
// by fire on July 27, 1998
// this is used to adjust the population in each area
// on regular schedule
void area_population_adjust(string p_id)
{
        int p_maxpopulation;
        int p_populationexpect;
        int p_seed;
        int p_population;
        int p_increase;
        switch(AREA_D->get_area(p_id,"level"))
        {
        case 1:
                p_maxpopulation=MAX_POPULATION1;
                break;
        case 2:
                p_maxpopulation=MAX_POPULATION2;
                break;
        case 3:
                p_maxpopulation=MAX_POPULATION3;
                break;
        case 4:
                p_maxpopulation=MAX_POPULATION4;
                break;
        case 5:
                p_maxpopulation=MAX_POPULATION5;
                break;
        }
        p_populationexpect=p_maxpopulation/100;
        p_populationexpect*=(AREA_D->get_area(p_id,"safe")+10);
        p_populationexpect/=300;
        p_populationexpect*=(AREA_D->get_area(p_id,"agriculture")+
                AREA_D->get_area(p_id,"industry")+
				AREA_D->get_area(p_id,"business")+30);
        p_population=AREA_D->get_area(p_id,"population");
        p_seed=p_population/20+100;
        p_increase=random(p_seed)-p_seed/6;
        if(p_populationexpect>p_population)
                p_population+=p_increase;
        else
                p_population-=p_increase;
        AREA_D->set_area(p_id,"population",p_population);
}
void adjust_population()
{
        string* list;
        list=AREA_D->list_areas();
        foreach(string p_id in list)
        {
                area_population_adjust(p_id);
        }
        return;
}
