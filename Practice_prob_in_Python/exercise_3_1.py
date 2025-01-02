class cookie:
    def __init__(self,color):
        self.color=color

    def get_color(self):
        return self.color
    
    def set_color(self,color):
        self.color=color

cookie_one=cookie("Green")
cookie_two=cookie("Blue")

print('Cookie one is',cookie_one.get_color())
print(f"Cookie two is {cookie_two.get_color()}")

cookie_one.set_color("Yellow")
print('Cookie one is',cookie_one.get_color())
print(f"Cookie two is {cookie_two.get_color()}")