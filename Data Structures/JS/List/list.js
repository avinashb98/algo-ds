class list {
  constructor() {
    this.pos = 0;
    this.dataStore = [];
    this.length = 0;
  }

  size() {
    return this.length;
  }

  clear() {
    delete this.dataStore;
    this.length = 0;
    this.pos = 0;
    return 1;
  }

  find(element) {
    for(let i = 0; i < this.length; i++) {
      if(this.dataStore[i] == element) {
        return i;
      }
    }
    return -1;
  }

  toString() {
    return this.dataStore;
  }

  insert(index, element) {
    if(index < this.length) {
      this.dataStore.splice(index, 0, element);
      this.length++;
      return 1;
    }
    return -1;
  }

  append(element) {
    this.dataStore.splice(this.length, 0, element);
    this.length++;
    return 1;
  }

  remove(element) {
    let index = this.find(element);
    if(index > -1) {
      this.dataStore.splice(index, 1);
      this.length--;
      return 1;
    }
    return -1;
  }

  front() {
    this.pos = 0;
  }

  end() {
    this.pos = this.length - 1;
  }

  prev() {
    if(this.pos >= 0) {
      this.pos--;
    }
  }

  next() {
    if(this.pos < this.length) {
      this.pos++;
    }
  }

  currPos() {
    return this.pos;
  }

  moveTo(index) {
    if(index >= 0 && index < this.length) {
      this.pos = index;
    }
  }

  getElement() {
    return this.dataStore[this.pos];
  }

  contains(element) {
    if(this.find(element) > -1) {
      return true;
    }
    return false;
  }

  pop() {
    let val = this.dataStore[this.length - 1];
    this.dataStore.splice(this.length - 1, 1);
    this.length--;
    return val;
  }
}

module.exports = list;
