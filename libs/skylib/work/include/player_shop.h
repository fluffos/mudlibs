/**
 * The header file for player-run shops.
 * The aim of the player-run shop is to provide an environment
 * where players can interact with each other, and the shop, with
 * no interference from creators.  Ideally, once the shop is set
 * up, and with the exception of the implementation of new features
 * or code maintenance, no further input should be required.  All
 * administration tasks can be performed by players.  These tasks
 * typically include:
 * <LI>adding and removing stock</LI>
 * <LI>personnel decisions (hiring/firing/disciplinary)</LI>
 * <LI>deciding what to stock & for how much it is bought/sold</LI>
 * <LI>increasing/decreasing stock capacity (for a price)</LI>
 * <LI>setting pay & bonus levels</LI>
 * <BR>
 * The only involvement needed by a creator after setup is the 
 * initial role of manager until employees have been promoted to
 * take this position.<BR>
 * <BR>
 * I will describe the workings of the shop in five sections.  These
 * will be from the point of view of a customer, employee, supervisor,
 * manager, and general.  This last section will discuss in greater
 * detail the way things work.<BR>
 * <BR>
 * Customers
 * From a customers' point of view, the shop should appear to function
 * similarly to a normal shop, with the obvious addition of players
 * acting as shopkeepers.  In the absence of players, there is an npc
 * shopkeeper to serve customers.  The npc has two customer interfaces.
 * Firstly, it will recognise the standard "buy", "sell", "list", "browse"
 * commands, and it will also recognise certain patterns of speech to
 * perform the same function.  The npc will then react to the customer's
 * request, performing the same actions as a player would.  A bell is
 * provided on the counter to alert any employees logged onto DW in the
 * event that the npc is not available.  Employees that are clocked in
 * are listed in the description of the shop front.  It is here that a
 * customer may make a complaint, suggestion, or apply for employment with
 * the shop.  These applications are mailed to each manager.  Confirmations
 * of employment, or cancellations of application are also made here.<BR>
 * <BR>
 * Employees
 * Once an application has been accepted, confirmed, and subject to any
 * vacancies, the applicant is hired and becomes an employee of the shop.
 * Employees are able to move past the counter into the room beyond.  From
 * here, it should be possible to access the office, storeroom and managers'
 * office.  Employees are responsible for replenishing stock and serving
 * customers.  Each is given a staff handbook and a special badge which
 * acts as a talker, allowing employees to keep in touch on a dedicated
 * channel.  This channel is also used by the shop bell to alert employees
 * to a customer in the shop.<BR>
 * Before undertaking any actions in the shop, it is important that the
 * employee clocks on in the office.  Also in the office is the shop's
 * chart, listing the lines of stock carried.  This chart displays the
 * buying and selling price, as well as the number of items currently
 * in stock.  The stock itself is held in the stockroom, in one or more
 * stock cabinets.  Each item is allocated a cabinet and the employee can
 * either place items in a specific cabinet, or let the stockroom work out
 * where they should go.  Similarly, an employee can specify which cabinet
 * to remove stock from, or let the stockroom determine that.  Listing stock
 * is an artform in itself - stock can be listed by item, cabinet, item in
 * cabinet, or all stock.  Creators have access to most commands - try it
 * for yourself.<BR>
 * When buying or selling items, the employee will need to handle money.
 * This is kept in the register behind the counter.  Along with the stock,
 * all changes made are logged and viewable by supervisors and managers.
 * The logbook behind the counter is for employees to record for themselves
 * what they have done and why.<BR>
 * Of course, a big incentive to do this work is to be paid for it.  Employees
 * are paid every DW month, direct into their bank account.  They also receive
 * a profit-related bonus each month, which they claim from the office.  Along
 * with the pay, they accumulate points towards promotion.  Promotion is now
 * not mandatory, and employees can deselect themselves if they wish not to be
 * promoted.  Any player with the "no score" property is automatically de-
 * selected.  Promotion is the only personnel issue that managers have no 
 * control over.  It is done automatically to minimise favouritism.  Once an
 * employee has achieved sufficient points, and subject to vacancies, they are
 * promoted to Supervisor.<BR>
 * <BR>
 * Supervisors
 * Supervisors receive a higher wage packet than employees - 1.5 times the
 * value, to be exact.  Their duties include those of the employees, with 
 * several additions.  They are responsible for deciding what items should
 * be bought and sold, and at what price.  Along with this, they assign
 * items to cabinets.  To assist them, they are able to view the general
 * and chart logs.  These logs indicate what is being bought/sold, and what
 * updates have been made to the chart.  Again, supervisors accumulate points
 * towards promotion, and will eventually be promoted to Manager.<BR>
 * <BR>
 * Managers
 * Managers receive double the wage of employees.  Their duties, however,
 * are quite involved.  They include setting staffing levels, pay rates,
 * renting new storage space, hiring/firing/disciplinary issues, and setting
 * the shop's policies.  This is in addition to the duties performed by
 * supervisors and employees.  Delegation would seem to play a part.<BR>
 * Managers cannot be promoted, and so have nothing to "work towards".
 * Experience has shown, however, that players in this position gain their
 * enthusiasm from the role itself, along with that pay packet.  This view
 * is reinforced by the fact that most managers will prefer to retire than
 * resign.  A retired manager has no active role in the shop, other than
 * voting on policy suggestions, and receives no pay.  Those employed by
 * Tarnach's have been shown to be happy acting as 'mentors'.<BR>
 * The main advantage of being a retired manager is the lack of commitment
 * needed - a manager must be very active in the shop, otherwise risking
 * demotion.  This demotion follows a warning, recorded on an employee's
 * record.  The same procedure applies to supervisors, within a longer 
 * timescale.  Employees have even longer, but risk being fired rather than
 * demoted.  These firings and demotions are automatic, and are one method
 * of staff turnover to help ensure a fair system to allow new employees
 * and promotions.  If an employee has a valid reason to be away, they can
 * notify a manager who can place them on leave.  This ensures they are
 * not fired or demoted if they are genuinely on holiday etc.<BR>
 * The code also includes a hook to the refresh handler.  The office is
 * registered automatically, and appropriate action taken when an employee
 * refreshes.  If the character is deleted, the employee data is also
 * deleted.  If an applicant refreshes, their application is terminated.
 * If a retired manager refreshes, their employment is terminated.  If any
 * other employee refreshes totally, their employment is terminated, but
 * if they only partially refresh, they revert to being a "new employee".
 * <BR>
 * General
 * This object is the nerve centre of the shop.  Most of the data structures
 * are defined and maintained from here, and virtually all of the managerial
 * functions are forwarded here.  It is this object that passes the common
 * variables across to other files as they call for them.  This minimises
 * the complexity of setting up each object - as long as they point to this
 * object, and this object is correctly set up, the objects will know which
 * shop they belong to, who the employees are, who the proprietor is etc.<BR>
 * Most of the functions defined in the office are not needed by creators.
 * Those that are needed are shown in the examples.  The other documented
 * functions are not necessary, but may be useful.<BR>
 * The data itself is saved into several files.  The data is arranged into
 * these files to minimise the amount of disk activity when changes are made.
 * For example, employee data changes every time an employee does something.
 * The list of applicants, however, changes only when an application status
 * changes.  They are, therefore, saved into seperate objects.  Also, each
 * save call is subject to a callout, and will limit the amount of disk
 * writing actually done. The only data not stored by this file is the stock
 * data, which is saved by each cabinet individually.  All data is saved to 
 * a secure directory under the shop name.<BR>
 * Logfiles are saved to a specified directory with the general log being
 * handled internally, all other logs handled by log_file().<BR>
 * The shop supports notice boards, posting all hirings, promotions, bonus
 * amounts in addition to any posts requested in the inheriting object.
 * In the absence of a board, all posts are mailed to each employee and
 * each employee will have access to an additional "memo" command in the
 * office.<BR>
 * Applications are handled automatically, with managers voting whether to
 * accept or reject an application.  On gaining positive votes from at least
 * 50% of the managers, an applicant is hired.  If they receive more than
 * 50% negative votes, they are rejected.  If there are insufficient votes
 * to settle the decision, it will be made based on votes cast after a 
 * period of time.  Policy suggestions are handled in a similar way.<BR>
 * <BR>
 * The shop's two main administration routines are run on a regular basis.
 * The first of these is run every day and is responsible for checking that
 * employees are still valid players (not deleted chars or creators).  It 
 * conducts automatic promotions, and handles demotions for inactive employees.
 * It also updates the lists of declined applicants and banned people and 
 * removes that status if applicable.  Finally, it calls the check_hire_list
 * function to see if we can hire any new employees.<BR>
 * The second is run every Discworld month.  This review involves paying
 * employees directly into their nominated bank account, and awarding bonuses
 * based on the current value of the bonus fund.<BR>
 *
 * @see /std/shops/player_shop/office.c
 * @see /std/shops/player_shop/mgr_office.c
 * @see /std/shops/player_shop/counter.c
 * @see /std/shops/player_shop/storerooom.c
 * @see /std/shops/player_shop/shop_front.c
 * @see /std/shops/player_shop/shopkeeper.c
 * @author Ringo
 * @started 1st August 1999
 */

#ifndef _PLAYER_SHOP_H
#define _PLAYER_SHOP_H

#define DEBUG
#undef TESTING

/**
 * Default maintainer of player shops.
 */
#define CREATOR "shiannar"

/**
 * The path to save data to
 */
#define SAVE_DIR "/save/player_shops/"
/**
 * Path to the shop cabinet object
 */
#define CABINET "/obj/misc/player_shop/shop_cabinet"
/**
 * Path to the shop badge object
 */
#define BADGE "/obj/misc/player_shop/shop_badge"
/**
 * Path to staff handbook
 */
#define STAFF_BOOK "/obj/misc/player_shop/staff_book"
/**
 * Path to the manager's handbook
 */
#define MGR_BOOK "/obj/misc/player_shop/mgr_book"
/**
 * Path to the shopping bag
 */
#define SHOP_BAG "/obj/misc/player_shop/shopping_bag"
/**
 * Path to the chart
 */
#define SHOP_CHART "/obj/misc/player_shop/shop_chart"
/**
 * Path to the policy notice
 */
#define SHOP_NOTICE "/obj/misc/player_shop/shop_notice"

/**
 * True value (1)
 */
#define TRUE 1
/**
 * False value (0)
 */
#define FALSE 0

/**
 * Employee mapping - points
 */
#define EMP_POINTS 0
/**
 * Employee mapping - last action time
 */
#define EMP_TIME 1
/**
 * Employee mapping - bank
 */
#define EMP_BANK 2
/**
 * Employee mapping - this month's pay
 */
#define EMP_PAY 3
/**
 * Employee mapping - inactivity flag
 */
#define EMP_INACTIVE 4
/**
 * Employee mapping - suspended bonus
 */
#define EMP_NOBONUS 5
/**
 * Employee mapping - Skip promotion.
 * This is done either at employee's request, or automatically
 * if the "no score" property is set.<br>
 * Set at -1 for "no score", or TRUE for employee request
 */
#define EMP_NOPROMOTE 6

/**
 * Employee bit - employee exists.
 */
#define EMPLOYEE 1
/**
 * Employee bit - employee is the npc shopkeeper.
 */
#define NPC 2
/**
 * Employee bit - employee is supervisor.
 */
#define SUPERVISOR 4
/**
 * Employee bit - employee is manager.
 */
#define MANAGER 8
/**
 * Employee bit - player is clocked in.
 */
#define CLOCKED_IN 16

/**
 * Number of points to become a manager.
 */
#define MANAGER_POINTS 1000
/**
 * Number of points to become a supervisor.
 */
#define SUPER_POINTS 500

/**
 * Banned people mapping - reason
 */
#define BAD_REASON 0
/**
 * Banned people mapping - banner 
 */
#define BAD_BANNER 1
/**
 * Banned people mapping - time of ban
 */
#define BAD_TIME 2

/**
 * Applications mapping - type of applicant
 */
#define APP_TYPE 0
/**
 * Applications mapping - time of application
 */
#define APP_TIME 1
/**
 * Applications mapping - votes for
 */
#define APP_FOR 2
/**
 * Applications mapping - votes against
 */
#define APP_AGAINST 3
/**
 * Applications mapping - abstentions
 */
#define APP_ABSTAIN 4

/**
 * Applicant types - Just applied
 */
#define APPLIED 1
/**
 * Applicant types - Voted in
 */
#define HIRED 2
/**
 * Applicant types - Awaiting a vacancy
 */
#define AWAITING 3

/**
 * Vote for an applicant
 */
#define VFOR      1
/**
 * Vote against an applicant
 */
#define VAGAINST  0
/**
 * Abstain on applicant
 */
#define VABSTAIN -1

/**
 * Minimum number of cabinets per storeroom
 */
#define MIN_CABINETS 5
/**
 * Maximum number of cabinets per storeroom
 */
#define MAX_CABINETS 20
/**
 * Maximum number of items per cabinet
 */
#define STOCK_PER_CABINET 50
/**
 * Maximum number of items in stock
 */
#define MAX_STOCK MAX_CABINETS * STOCK_PER_CABINET
/**
 * Price of cabinets
 */
#define CABINET_COST 400000

/**
 * Log entries - manual entry
 */
#define LOG_ENTRY 1
/**
 * Log entries - items purchased by shop.
 * Items added to stock, cash removed from till
 */
#define PURCHASE 2
/**
 * Log entries - items sold by shop.
 * Items removed from stock, cash added to till
 */
#define SALE 3
/**
 * Log entries - personnel issues (hire, fire, promote, demote,
 * warnings, retire, resign, on leave etc)
 */
#define PERSONNEL 4
/**
 * Log entries - accounts (pay/bonus/profit)
 */
#define ACCOUNTS 5
/** 
 * Log entries - general entries
 */
#define GENERAL 6
/**
 * Log entries - chart changes
 */
#define CHARTLOG 7

/**
 * Chart mapping - maximum stock
 */
#define CHART_MAX 0
/**
 * Chart mapping - average stock
 */
#define CHART_AVE 1
/**
 * Chart mapping - buy price
 */
#define CHART_BUY 2
/**
 * Chart mapping - sell price
 */
#define CHART_SELL 3
/**
 * Chart mapping - stock cabinet(s) used by this item
 */
#define CHART_CAB 4
/**
 * Chart mapping - average daily sales
 */
#define CHART_AVESALE 5
/**
 * Chart mapping - daily sales
 */
#define CHART_SOLD 6
/**
 * Chart mapping - daily purchases
 */
#define CHART_BOUGHT 7

/**
 * Path to the history handler used for chats through the badge
 */
#define HISTORY "/handlers/hist_handler"
/**
 * Path to the bank handler
 */
#define BANK "/handlers/bank_handler"
/**
 * Path to the refresh handler
 */
#define REFRESH "/handlers/refresh"

/**
 * List of banks.
 * The list is formatted as ({ ({ "Description", "Name" }) })<br>
 * Any new banks must be added to the end of this list to avoid 
 * upsetting existing employees ;-)
 */
#define BANKS ({ ({ "XXXXXX", "XXXXXX", }), \
              })

/**
 * How long to prevent someone ringing the shop bell again (seconds)
 */
#define BELL_TIMEOUT 120

/**
 * Minimum number of employees per shop
 */
#define MIN_EMP 10
/**
 * Maximum number of employees per shop
 */
#define MAX_EMP 40
/**
 * Percentage of employees that can be managers
 */
#define PERCENT_M 10
/**
 * Percentage of employees that can be supervisors
 */
#define PERCENT_S 20


/**
 * Default pay amount
 */
#define START_PAY 20

/** 
 * Maximum number of consecutive days an employee can be on leave
 */
#define MAX_LEAVE 14
/**
 * Length of ban from shop in days
 */
#define BAN_LENGTH 28
/**
 * Length of time (days) before an applicant can re-apply
 */
#define DECLINE_LENGTH 14
/**
 * Time (days) before managers demoted for inactivity
 */
#define MGR_DEMOTE 14
/**
 * Time (days) before managers warned for inactivity
 */
#define MGR_WARN 7
/**
 * Time (days) before supervisors demoted for inactivity
 */
#define SPR_DEMOTE 28
/**
 * Time (days) before supervisors warned for inactivity
 */
#define SPR_WARN 14
/**
 * Time (days) before employees fired for inactivity
 */
#define EMP_FIRE 62
/**
 * Time (days) before employees warned for inactivity
 */
#define EMP_WARN 14



/**
 * Length of time (days) to keep shop's logs
 */
#define LOG_DAYS 14

/**
 * Length of time (seconds) for hired applicants to confirm
 * their employment.
 */
#define HIRE_TIMEOUT 60*60*24*14

/**
 * Length of time (seconds) for a player's history to expire if
 * there has been no update.
 */
#define HIST_TIMEOUT 60*60*24*91

/**
 * Shopkeeper's movement & command delay
 */
#define NPC_DELAY 2 + random( 3 )
/**
 * Shopkeeper's reload delay (seconds)
 */
#define NPC_RELOAD 60*60

/**
 * Call-out delay for saving employee & shop data
 */
#define SAVE_DELAY 1
/**
 * Call-out delay for saving personnel data
 */
#define PERS_DELAY

/**
 * Prompt shown to player making a complaint
 */
#define COMPLAINT_TEXT "Please fully state your complaint below.  " \
                       "Include as much detail as you can and any " \
                       "evidence/witnesses to support your complaint."

/**
 * Prompt shown to player making a suggestion
 */
#define SUGGEST_TEXT "Please detail your suggestion below."

/**
 * Questions to ask an applicant for a job
 */
#define APP_QUESTIONS ({ "Why do you want to work for "+ \
                     _office->query_shop_name()+ "?", \
                     "What is your character's age?", \
                     "What relevant experience do you have of collecting " \
                      " and/or recognising our stock?", \
                     "How much time (hours/week) do you think you can " \
                     "commit to the shop?  Please also tell us at what " \
                     "time you will usually be on.", \
                     "Do you already know anyone who is an employee " \
                     "here, who could recommend you?  If so, who?", \
                     "Have you previously held a position at this shop?  " \
                     "If so, why did you leave?", \
                     "Do you currently work at any other shop?", \
                     "Have you applied for employment here before?  " \
                     "If so, what was the outcome?", \
                     "Do you have anything else you'd like to tell us in " \
                     "support of your application?  Please expand on above " \
                     "points if necessary.  What you say here will influence " \
                     "whether or not you are hired." \
                })
#endif
