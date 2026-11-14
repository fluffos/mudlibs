// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/master/domain-compat.inc
// Description: Domain-Abfragen auf /apps/domains weiterleiten
// Author:	Gnomi (14.07.2004)
//
// $Log: domain_compat.inc,v $
// Revision 1.1  2004/07/19 21:30:54  gnomi
// Domain-Infos vom Master nach /apps/domains umgezogen.
//

string *query_domains()
{
    return ({string*})DOMAIN_INFOS->query_domains();
}

int domain_member(string domain, string name)
{
    return ({int})DOMAIN_INFOS->domain_member(domain, name);
}

int domain_lord(string domain, string player)
{
    return ({int})DOMAIN_INFOS->domain_lord(domain, player);
}

int domain_helfer(string domain, string player)
{
    return ({int})DOMAIN_INFOS->domain_helfer(domain, player);
}

string *query_domain_lords(string domain)
{
    return ({string*})DOMAIN_INFOS->query_domain_lords(domain);
}

string *query_domain_helfer(string domain)
{
    return ({string*})DOMAIN_INFOS->query_domain_helfer(domain);
}

string *query_domain_members(string domain)
{
    return ({string*})DOMAIN_INFOS->query_domain_members(domain);
}

string *query_domains_of(string lord)
{
    return ({string*})DOMAIN_INFOS->query_domains_of(lord);
}

string *query_memberships_of(string wiz)
{
    return ({string*})DOMAIN_INFOS->query_memberships_of(wiz);
}

string *query_domainhelfer_of(string wiz)
{
    return ({string*})DOMAIN_INFOS->query_domainhelfer_of(wiz);
}

int add_domain_member(string domain, string wiz)
{
    return ({int})DOMAIN_INFOS->add_domain_member(domain, wiz);
}

int delete_domain_member(string domain, string wiz)
{
    return ({int})DOMAIN_INFOS->delete_domain_member(domain, wiz);
}

int add_domain_lord(string domain, string wiz, int pos)
{
    return ({int})DOMAIN_INFOS->add_domain_lord(domain, wiz, pos);
}

int delete_domain_lord(string domain, string wiz)
{
    return ({int})DOMAIN_INFOS->delete_domain_lord(domain, wiz);
}

int add_domain_helfer(string domain, string wiz, int pos)
{
    return ({int})DOMAIN_INFOS->add_domain_helfer(domain, wiz, pos);
}

int delete_domain_helfer(string domain, string wiz)
{
    return ({int})DOMAIN_INFOS->delete_domain_helfer(domain, wiz);
}

int add_domain(string domain)
{
    return ({int})DOMAIN_INFOS->add_domain(domain);
}

int delete_domain(string domain)
{
    return ({int})DOMAIN_INFOS->delete_domain(domain);
}

void check_domains()
{
    DOMAIN_INFOS->check_domains();
}
