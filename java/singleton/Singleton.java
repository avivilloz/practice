public class Singleton<T> {
    private static T instance = null;
    private Singleton() {}
    public synchronized static <T> T GetInstance() {
        if (null == instance)
        {
            instance = new T();
        }
        return instance;
    }
}