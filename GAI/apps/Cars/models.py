from django.db import models


class Owner(models.Model):
    name = models.CharField(max_length=255)
    surname = models.CharField(max_length=255)
    last_name = models.CharField(max_length=255, default='', blank=True)
    birth_date = models.DateField()

    def __str__(self):
        return f"{self.name} {self.surname}"

    class Meta:
        verbose_name = "Владелец"
        verbose_name_plural = "Владельцы"


class Brand(models.Model):
    brand = models.CharField(max_length=255, verbose_name='бренд', unique=True)

    def __str__(self):
        return self.brand

    class Meta:
        verbose_name = "Бренд"
        verbose_name_plural = "Бренды"


class Model(models.Model):
    brand = models.ForeignKey(Brand, on_delete=models.CASCADE)
    model = models.CharField(max_length=255, verbose_name='брэнд', unique=True)

    def __str__(self):
        return f"{self.brand} {self.model}"

    class Meta:
        verbose_name = "Модель"
        verbose_name_plural = "Модели"


class Car(models.Model):
    template_number = models.CharField(max_length=12, verbose_name="Номер автомобиля", unique=True)
    motor_number = models.CharField(max_length=255, verbose_name="Номер двигателя", unique=True)
    model = models.ForeignKey(Model, on_delete=models.CASCADE)
    # brand = models.CharField(max_length=255, verbose_name="Марка")
    # model = models.CharField(max_length=255, verbose_name="Модель")
    color = models.CharField(max_length=255, verbose_name="Цвет")
    registration_date = models.DateField(max_length=255, verbose_name="Дата регистрации")
    owner = models.ForeignKey(Owner, on_delete=models.CASCADE)
    is_stolen = models.BooleanField(verbose_name="Автомобиль угнан")
    prev_ovner = models.ManyToManyField(Owner, related_name="prev", blank=True)

    def __str__(self):
        return f"{self.owner} {self.model}    {'В угоне!' if self.is_stolen else ''}"

    class Meta:
        verbose_name = "Автомобиль"
        verbose_name_plural = "Автомобили"


class Crash(models.Model):
    date = models.DateField()
    car = models.ManyToManyField(Car)

    def __str__(self):
        return f"{self.date}"

    class Meta:
        verbose_name = "Авария"
        verbose_name_plural = "Аварии"
