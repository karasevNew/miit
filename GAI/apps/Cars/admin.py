from django.contrib import admin
from .models import Owner, Car, Crash, Model, Brand
admin.site.register(Owner)
admin.site.register(Crash)
admin.site.register(Car)
admin.site.register(Model)
admin.site.register(Brand)
