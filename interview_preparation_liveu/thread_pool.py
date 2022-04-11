from threading import Thread, Semaphore
import time

class ThreadPool:
    def initial_setup(self, num_of_workers):
        # self.workers = [self.Worker(self)] * num_of_workers
        for i in range(0, num_of_workers):
            self.workers.append(self.Worker(self, i))

    def do(self, task, args):
        self.tasks.append(self.Task(task, args))
        self.sem.release()

    def __get_task__(self):
        self.sem.acquire()
        return self.tasks.pop(0)

    workers = []
    tasks = []
    sem = Semaphore(0)

    class Task:
        def __init__(self, task, args) -> None:
            self.task = task
            self.args = args
        
    class Worker:
        def __work__(self, pool):
            while self.should_work:
                task = pool.__get_task__(pool)
                self.__print_num__()
                task.task(task.args)

        def __init__(self, pool, num):
            self.should_work = True
            self.thread = Thread(target = self.__work__, args = (pool, ))
            self.thread.start()
            self.thread_num = num
            
        def __print_num__(self):
            print("Thread num: " + str(self.thread_num))



def task(args):
    # print("working " + str(args[0]) + " " + str(args[1]))
    time.sleep(args[0])

pool = ThreadPool
pool.initial_setup(pool, 12)
for i in range(0, 24):
    pool.do(pool, task, (i, i + 25))