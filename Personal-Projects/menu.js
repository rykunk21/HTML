let menu = {
    _courses: {
      appetizers: [],
      mains: [],
      desserts: []
    },
  
    get appetizers() {
      return this._courses.appetizers
    }, 
    set appetizers(appetizer) {
      this._courses.appetizer = appetizer;
    },
    get mains() {
      return this._courses.mains
    }, 
    set mains(mains) {
      this._courses.mains = mains;
    },
    get desserts() {
      return this._courses.desserts
    }, 
    set desserts(desserts) {
      this._courses.desserts = desserts;
    },
    get courses(){
      return this._courses;
    },
  
    addDishToCourse(courseName, dishName, dishPrice){
      dish = {
        name: dishName,
        price: dishPrice
      }
      this._courses[courseName].push(dish);
    },
  
    getRandomDishFromCourse(courseName){
      dishes = this._courses[courseName];
      index = Math.floor(Math.random() * dishes.length);
      return dishes[index];    
    },
  
    generateRandomMeal(){
      const appetizer = this.getRandomDishFromCourse('appetizers');
      const main = this.getRandomDishFromCourse('mains');
      const dessert = this.getRandomDishFromCourse('desserts');
      const total_price = appetizer.price + main.price + dessert.price;


      return `Appetizer: ${appetizer.name}, Main: ${main.name}, Dessert: ${dessert.name}, Total Price: ${total_price}`;
  
    }
  }
  
  
  menu.addDishToCourse('appetizers', 'Fried Pickles', 6.99);
  menu.addDishToCourse('appetizers', 'Wings', 14.99);
  menu.addDishToCourse('appetizers', 'Cantalope', 0.00);
  menu.addDishToCourse('mains', 'Surf and Turf', 54.99);
  menu.addDishToCourse('mains', 'Boillibase', 34.00);
  menu.addDishToCourse('mains', 'Baked Pasta', 14.00);
  menu.addDishToCourse('desserts', 'Chocolate Torte', 9.00);
  menu.addDishToCourse('desserts', 'Cheesecake', 9.00);
  menu.addDishToCourse('desserts', 'Cannoli', 14.00);
  
  
console.log(menu.generateRandomMeal());
  
  