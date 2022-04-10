from threading import Thread, Lock

# lock.acquire(), lock.release()

class ThreadPool:
    def initial_setup(self, num_of_workers):
        self.workers = [self.Worker(self)] * num_of_workers

    def do(self, task, args):
        task_delivered = False
        while not task_delivered:
            self.mutex.acquire()
            if self.workers:
                worker = self.workers[0]
                self.workers.pop(0)
                worker.task = task
                worker.args = args
                worker.start()
            else:
                print("all workers busy")
            self.mutex.release()


    def __get_back_to_line__(self, worker):
        self.mutex.acquire()
        self.workers = [worker] + self.workers
        self.mutex.release()

    workers = []
    mutex = Lock

    class Worker:
        def work(self, pool):
            self.task(self.args)
            pool.__get_back_to_line__(pool, self)

        def clean_the_floor(args):
            print("cleaning the floor with " + args)
            pass

        def __init__(self, pool):
            objects = (self, pool)
            thread = Thread(target = self.work, args = objects)
            task = self.clean_the_floor
            args = ()


def task(args):
    print("working" + str(args[1]) + " " + str(args[2]))
pool = ThreadPool
pool.initial_setup(pool, 12)