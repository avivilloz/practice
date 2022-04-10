import time
from threading import Thread


class CacheSystem:

    class Timer:
        def thread_timer(self, object, id, callback, timeout):
            time.sleep(timeout)
            callback(object, id)
            self.threads.pop(id)

        def start_timer(self, object, id, callback, timeout):
            thread = Thread(target = self.thread_timer, args = (self, object, id, callback, timeout))
            thread.start()
            self.threads[id] = thread

        threads = {}

    def add(self, id, data):
        self.cache[id] = data
        self.timer.start_timer(self.timer, self, id, self.remove, self.remove_time)

    def remove(self, id):
        print("removing id " + str(id) + " with data " + str(self.cache[id]))
        self.cache.pop(id)

    def pull(self, id):
        return self.cache.pop(i)

    timer = Timer
    cache = {}
    remove_time = 3


cache = CacheSystem
for i in range(0, 25):
    cache.add(cache, i, i +25)

# for i in range(0, 25):
#     print(cache.pull(cache, i))

time.sleep(50)