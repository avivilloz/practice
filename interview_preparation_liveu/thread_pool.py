from threading import Thread, Lock, Condition
import time

# lock.acquire(), lock.release()

class ThreadPool:
    def initial_setup(self, num_of_workers):
        self.workers = [self.Worker(self, cond)] * num_of_workers

    def do(self, task, args):
        task_delivered = False
        while not task_delivered:
            # self.mutex.acquire()
            if self.workers:
                worker = self.workers[0]
                self.workers.pop(0)
                worker.task = task
                worker.args = args
                worker.has_task = True
                self.cond.notify()
            else:
                print("all workers busy")
            self.cond.wait()
            # self.mutex.release()

    def get_task(self):
        self.cond.wait()
        return self.tasks[0]

    workers = []
    tasks = []
    cond = Condition()

    class Worker:
        def __work__(self, pool, cond):
            while self.should_work:
                task = pool.get_task()
                task[0](task[1])

        def __init__(self, pool, cond):
            self.should_work = True
            self.thread = Thread(target = self.__work__, args = (pool, cond))
            self.thread.start()


def task(args):
    print("working" + str(args[1]) + " " + str(args[2]))
    time.sleep(args[1])

pool = ThreadPool
pool.initial_setup(pool, 12)
for i in range(0, 24):
    pool.do(pool, task, (i, i + 25))