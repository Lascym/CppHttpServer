#pragma once
#include"Dispatcher.h"
#include<sys/epoll.h>
#include<string>
using namespace std;

class EpollDispatcher:public Dispatcher
{
public:
    EpollDispatcher(EventLoop* evloop);
    ~EpollDispatcher();
    // 添加
    int add() override;
    // 删除
    int remove() override;
    // 修改
    int modify() override;
    // 事件检测
    int dispatch(int timeout=2) override; //单位 s
private:
    int epollCtl(int op);
private:
    int m_epfd;
    struct epoll_event* m_events;
    const int m_maxNode=520;
};