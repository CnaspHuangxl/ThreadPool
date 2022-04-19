#include"ThreadPool.h"
#include"unistd.h"
#include<iostream>
void taskFunc(void* arg)
{
    int num = *(int*)arg;
    cout<<"thread" <<pthread_self()<<"is working, number = "<<num<<endl;
    sleep(1);
}

int main()
{
    ThreadPool pool(3, 10);
    // �����̳߳�
    for (int i = 0; i < 100; ++i)
    {
        int* num = new int(i+100);
        pool.addTask(Task(taskFunc, num));
    }

    sleep(20);

    return 0;
}

