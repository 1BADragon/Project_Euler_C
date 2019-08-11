use std::vec::Vec;
use std::string::String;
use std::ops;
use std::cmp;
use std::fmt;

#[derive(Clone)]
pub struct Bigint {
    val: Vec<u8>
}

impl Bigint {
    pub fn new() -> Bigint {
        Bigint{
            val: Vec::new()
        }
    }
    
    pub fn from_vec(val:Vec<u8>) -> Bigint{
        Bigint{
            val: val
        }
    }
    
    pub fn from_int(num:i32) -> Bigint{
        let mut temp = num;
        let mut val:Vec<u8> = Vec::new();
        
        while temp > 0 {
            val.push((temp % 10) as u8);
            temp = temp / 10;        
        }
        
        Bigint{
            val: val
        }
    }

    pub fn is_zero(&self) -> bool{
        if self.val.len() == 0 {
            return true;
        }
        for x in self.val.iter() {
            if *x != 0 {
                return false;
            }
        }

        return true;
    }
}

impl ops::Mul for Bigint{
    type Output = Bigint;

    fn mul(self, other:Bigint) -> Bigint{
        let mut carry:u8 = 0;
        let mut num:u8 = 0;
        let mut ten = 0;
        for i in self.val.iter() {
            for j in other.val.iter() {
                
            }
        }
    }
}

impl ops::Add for Bigint{
    type Output = Bigint;
    
    fn add(self, other:Bigint) -> Bigint{
        let mut res = Bigint::new();
        let mut num:u8 = 0;
        let len = cmp::max(self.val.len(), other.val.len());
        let mut carry:u8 = 0;
        for x in 0..len {
            num = 0;
            if x < self.val.len() {
                num += self.val[x];
            }
            if x < other.val.len() {
                num += other.val[x];
            }
            num += carry;
            if num > 9 {
                carry = num % 10;
                num -= 10;
            }
            else
            {
                carry = 0;
            }
            res.val.push(num);
        }
        if carry > 0 {
            res.val.push(carry);
        }
        return res;
    }
}

impl fmt::Display for Bigint {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        let len = self.val.len();
        let mut res = String::new();        
        
        for i in 0..len {
            res += self.val[(len - i) - 1].to_string().as_str();
        }
        
        write!(f, "{}", res)        
    }
}
