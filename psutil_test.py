import psutil

print("Данные о процессоре с момента загрузки (количество системных вызовов и контекстных переключателей)")
print(psutil.cpu_stats())

print("Данные о диске")
print(psutil.disk_usage("c:"))

print("Данные о состояния памяти")
print(psutil.virtual_memory())

print("Данные о времени автономной работы")
print(psutil.sensors_battery())

