// cuised.c 漫游精灵

#include <ansi.h>
#include <mudlib.h>

#pragma optimize
#pragma save_binary

// 漫游精灵如何工作？
// 每个站点的漫游精灵负责进行认证和数据传输。启动以后，漫游
// 精灵会监听一个端口，查询来自其他站点的请求。
//
// 分身漫游：
// 如果某个站点登陆了其他站点漫游过来的使用者，则本站点从原
// 始站点漫游精灵那里获得该玩家的数据，包括 login & user 两
// 部分。然后根据这些数据在本站点构造一个玩家，但是这些数据
// 并不会在本站保存或是退出的时候传递回原先的站点。巫师使用
// 这种方式进行漫游。
//
// 认证流程：
// 漫游精灵接受来自连线精灵的数据验证请求，并将从需要请求得
// 站点或的数据。发送请求是需要包括用户名和口令 -- 这个必须
// 通过一定手段进行保密。接受请求以后将查验是否正确并返回相
// 应的信息。接收到返回的正确信息以后，漫游精灵重新驱动起连
// 线精灵。
//

// 监听的端口(以MUD的启动端口为基准)
#define CRUISE_PORT                     13

// 同时可验证的最大人数
#define MAX_AUTHENTICATING_USER         32

// 验证等待的最长时间(秒)
#define MAX_AUTHENTICATING_TIME         180

// 内部变量
static int cfd;
mixed auth_info = ({ });

// 提供给外部的接口
void authenticate_user(object ob, string passwd);

private void server_init();
private void in_listen_callback(int fd);
private void in_read_callback(int fd, string str);
private void in_write_callback(int fd);
private void in_close_callback(int fd);

void create() 
{
	seteuid(ROOT_UID);
	set("channel_id", "漫游精灵");

        call_out("server_init", 0);
}

// 提供版本服务
private void server_init()
{
        int port;

        CAHNNEL_D->do_channel(this_object(), "sys", "漫游精灵启动。");

        // 创建漫游通讯的SOCKET
        cfd = socket_create(STREAM_BINARY,
                            "in_read_callback",
                            "in_close_callback" );

	if (cfd < 0)
        {
                log_file("cruise", sprintf("%s Failed to create socket.\n", log_time()));
		return;
	}

        // 然后绑定SOCKET
        port = get_config(__MUD_PORT__) + CRUISE_PORT;
	if (socket_bind(cfd, port) < 0)
        {
		log_file("cruise", sprintf("%s Failed to bind socket.\n", log_time()));
		socket_close(cfd);
		return;
	}

        // 最后监听
	if (socket_listen(vfd, "in_listen_callback" ) < 0)
        {
		log_file("cruise", sprintf("%s Failed to listen to socket.\n", log_time()));
		return;
	}

        // 初始化连接信息
        socket_info = ([ ]);
}

// 版本发布站监听来自其他站点的请求
private void in_listen_callback(int fd)
{
	int new_fd;
        string address;
        string ip;
        int port;

	if ((new_fd = socket_accept(fd, "in_read_callback",
                                        "in_write_callback")) < 0)
                // 没有成功的接收这个连接请求
		return;

        address = socket_address(new_fd);
        if (! stringp(address) || sscanf(address, "%s %d", ip, port) != 2 ||
            ! CONFIG_D->query(ip))
        {
                // 这个地址没有经过授权
                socket_close(new_fd);
                return;
        }

        sys_info(sprintf("站点 %s 连接版本开始同步版本。", ip));

        socket_info[new_fd] = allocate(7);
	socket_info[new_fd][STATUS] = STATUS_LOGIN;
        socket_info[new_fd][CMD_BUFFER] = "";
        socket_info[new_fd][CMD_QUEUE] = ({ });
        socket_info[new_fd][PENDING_WRITE] = ({ });

        // 更新状态
        socket_info[new_fd][STATUS] = STATUS_WAIT_COMMAND;
	in_write_callback(new_fd);
}

// 接受信息
private void in_read_callback(int fd, mixed mess)
{
        int cc;
	string *cmds;
        mixed  prefix;
        string str;

	if (! arrayp(socket_info[fd]))
                return;

        if (stringp(mess))
                // 接收到了字符串
                str = mess;
        else
        if (bufferp(mess))
                // 接收到了缓冲区
                str = read_buffer(mess, 0, sizeof(mess));
        else
                return;

        if (! str) return;

	str = replace_string( str, "\r", "");
        if (stringp(prefix = socket_info[fd][CMD_BUFFER]))
                str = (string) prefix + str + "\n";
        else
                str += "\n";

	cmds = explode(str, "\n");
        socket_info[fd][CMD_BUFFER] = cmds[sizeof(cmds) - 1];

        if (sizeof(cmds) > 1)
        {
                // 将这些命令放入到命令队列中
                cc = sizeof(socket_info[fd][CMD_QUEUE]);
                socket_info[fd][CMD_QUEUE] += cmds[0..<2];
                if (socket_info[fd][STATUS] == STATUS_WAIT_COMMAND)
                        // 正在接受命令状态
                        parse_cmd(fd);
        }
}

// 成功写入
private void in_write_callback(int fd)
{
        buffer buf;
        int pos, len;
        int i;

        for (i = 0; i < 32; i++)
        {
                // 循环处理消息
                reset_eval_cost();

                // 已经处理完了？
        	if (! arrayp(socket_info[fd]))
                        // 是，这个不需要继续处理了
                        return;

                // 如果有阻塞的普通消息，则我发送出去
                while (sizeof(socket_info[fd][PENDING_WRITE]))
                {
                        // 有阻塞的消息，发送之
                        if (send_pending_msg(fd) != 0)
                                // 没有成功的发送，等待下一次发送
                                return;
                }

                // 根据当前的状态进行进一步处理
                switch (socket_info[fd][STATUS])
                {
                case STATUS_SENDING:
                        // 正在发送文件
                        pos = socket_info[fd][FILE_POS];
                        len = socket_info[fd][FILE_SIZE] - pos;
                        if (len > FILE_BLOCK)
                                len = FILE_BLOCK;
                        if (len > 0)
                        {
                                buf = read_buffer((string) socket_info[fd][FILE_NAME], pos, len);
                                if (sizeof(buf) != len)
                                        // 读取没有完全成功？填写零发送。
                                        buf = allocate_buffer(len);
                                // 判断这次操作的结果
                                switch (socket_write(fd, buf))
                                {
                                case EESUCCESS:
                                        // 移动游标
                                        pos += len;
                                        break;

                                case EECALLBACK:
                                        // 移动游标
                                        pos += len;

                                        // 等待CALLBACK，先不继续处理
                                        socket_info[fd][FILE_POS] = pos;
                                        return;

                                case EEWOULDBLOCK:
                                        // 发送忙
                                        call_out("in_write_callback", 2, fd);
                                        return;

                                default:
                                        // 发送失败，等待下次callback
                                        return;
                                }
                        }

                        // 判断文件是否发送完毕
                        if ((socket_info[fd][FILE_POS] = pos) >=
                            socket_info[fd][FILE_SIZE])
                        {
                                // 文件已经发送完毕，更新状态
                                socket_info[fd][STATUS] = STATUS_WAIT_COMMAND;
                                if (! sizeof(socket_info[fd][CMD_QUEUE]))
                                        // 已经没有待处理的命令了
                                        return;

                                // 继续处理命令：为什么要用
                                // this_object() 进行呼叫？
                                // 这个是不能省略的，因为这
                                // 样其它部分的函数就可以根
                                // 据previous_object() 分辨
                                // 是否试运行在callback内。
                                this_object()->parse_cmd(fd);

                                // 继续，循环将会处理命令产生的结果
                        }

                        // 发送处理完毕
                        break;
        
                default:
                        // 未定义状态，无操作
                        return;
                }

                // 一次处理(switch)完毕，循环继续处理
        }

        // 运行太久了
        debug_info("向 SOCKET 写入数据太多，暂缓。");
        call_out("in_write_callback", 1, fd);
}

// 连接断开
private void in_close_callback(int fd)
{
        string address;

        address = socket_address(fd);
        if (stringp(address))
                sscanf(address, "%s %*d", address);
        else
                address = "unknow";

        sys_info(sprintf("站点 %s 和本站断开了连接。", address));

        // 清除信息
        map_delete(socket_info, fd);
}

// 供 LOGIN_D 调用的接口
int authenticate_user(object ob, string passwd)
{
        string site;
        string id;
        object aob;
        mixed info;
        int i;

        if (! stringp(site = ob->query_temp("site")))
                return 0;

        if (! stringp(id = ob->query("id")))
                return 0;

        if (! interactive(ob))
                return 0;

        if (site == INTERMUD_MUD_NAME)
                return 0;

        for (i = 0; i < sizeof(auth_info); i++)
        {
                if (! objectp(aob = auth_info[i][USER_OB]))
                        continue;

                if (! interactive(aob))
                {
                        destruct(aob);
                        auth_info[i] = 0;
                        continue;
                }
                        
                if (info[USER_ID] != id)
                        continue;

                if (query_ip_number(aob) == query_ip_number(ob))
                {
                        tell_object(aob, "认证中止。\n");
                        destruct(aob);
                        auth_info[i] = 0;
                }
        }

        info = allocate(USER_MAGIC_NUMBER + 1);
        info[USER_ID] = id;
        info[USER_OB] = ob;
//      info[USER_PASSWD] = passwd;
        info[USER_SITES] = site;
        info[USER_MAGIC_NUMBER] = time();

        auth_info -= ({ 0 });
        auth_info += ({ info });
}
