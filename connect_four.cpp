/*
*Author :Tharindra Galahena
*Project:Connect - Four A.I. Agent
*Date   :25/10/2012
*License:
* 
*     Copyright 2012 Tharindra Galahena
*
* This program is free software: you can redistribute it and/or modifood_y it under the 
* terms of the GNU General Public License as published by the Free Software Foundation, 
* either version 3 of the License, or (at your option) any later version. This program is 
* distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even 
* the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with This program. 
* If not, see http://www.gnu.org/licenses/.
*
*/

using namespace std;

class state{
	public:
		int steps;
		int value;
		int lavel[7];
		char bord[6][7];
		state();
		state(const state &source);
		int get_minimax();
		void update(int i, char player);
		int get_max_char_value(char c);
		int get_min_char_value(char c);
		void reset();
};
state::state(){
	steps = 0;
	value = 0;
	lavel[0] = 5;
	lavel[1] = 5;
	lavel[2] = 5;
	lavel[3] = 5;
	lavel[4] = 5;
	lavel[5] = 5;
	lavel[6] = 5;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			bord[i][j] = ' ';
		}
	}
}
state::state(const state &source){
	value = source.value;
	steps = source.steps;
	lavel[0] = source.lavel[0];
	lavel[1] = source.lavel[1];
	lavel[2] = source.lavel[2];
	lavel[3] = source.lavel[3];
	lavel[4] = source.lavel[4];
	lavel[5] = source.lavel[5];
	lavel[6] = source.lavel[6];
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			bord[i][j] = source.bord[i][j];
		}
	}
}
void state::reset(){
	steps = 0;
	value = 0;
	lavel[0] = 5;
	lavel[1] = 5;
	lavel[2] = 5;
	lavel[3] = 5;
	lavel[4] = 5;
	lavel[5] = 5;
	lavel[6] = 5;
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 7; j++){
			bord[i][j] = ' ';
		}
	}
}
int state::get_max_char_value(char c){
	if(c == ' ') return 1;
	if(c == '0') return 5;
	if(c == '#') return 21; 
}
int state::get_min_char_value(char c){
	if(c == ' ') return 1;
	if(c == '#') return 5;
	if(c == '0') return 21; 
}
int state::get_minimax(){
	int max1 = 0;
	int max2 = 0;
	//check raws
	for(int i = 0; i < 6; i++){
		//Human
		int sum = 0;
		for(int j = 0; j < 4; j++){
			sum += get_max_char_value(bord[i][j]);
		}
		if(sum == 20) return -20;
		if(sum < 20){
			if(sum > max1)
				max1 = sum;
		}
		sum = 0;
		for(int j = 1; j < 5; j++){
			sum += get_max_char_value(bord[i][j]);
		}
		if(sum == 20) return -20;
		if(sum < 20){
			if(sum > max1)
				max1 = sum;
		}
		sum = 0;
		for(int j = 2; j < 6; j++){
			sum += get_max_char_value(bord[i][j]);
		}
		if(sum == 20) return -20;
		if(sum < 20){
			if(sum > max1)
				max1 = sum;
		}
		sum = 0;
		for(int j = 3; j < 7; j++){
			sum += get_max_char_value(bord[i][j]);
		}
		if(sum == 20) return -20;
		if(sum < 20){
			if(sum > max1)
				max1 = sum;
		}
		//A.I.
		sum = 0;
		for(int j = 0; j < 4; j++){
			sum += get_min_char_value(bord[i][j]);
		}
		if(sum == 20) return 20;
		if(sum < 20){
			if(sum > max2)
				max2 = sum;
		}
		sum = 0;
		for(int j = 1; j < 5; j++){
			sum += get_min_char_value(bord[i][j]);
		}
		if(sum == 20) return 20;
		if(sum < 20){
			if(sum > max2)
				max2 = sum;
		}
		sum = 0;
		for(int j = 2; j < 6; j++){
			sum += get_min_char_value(bord[i][j]);
		}
		if(sum == 20) return 20;
		if(sum < 20){
			if(sum > max2)
				max2 = sum;
		}
		sum = 0;
		for(int j = 3; j < 7; j++){
			sum += get_min_char_value(bord[i][j]);
		}
		if(sum == 20) return 20;
		if(sum < 20){
			if(sum > max2)
				max2 = sum;
		}
	}
	//check colomns
	for(int i = 0; i < 7; i++){
		//Huamn
		int sum = 0;
		for(int j = 0; j < 4; j++){
			sum += get_max_char_value(bord[j][i]);
		}
		if(sum == 20) return -20;
		if(sum < 20){
			if(sum > max1)
				max1 = sum;
		}
		sum = 0;
		for(int j = 1; j < 5; j++){
			sum += get_max_char_value(bord[j][i]);
		}
		if(sum == 20) return -20;
		if(sum < 20){
			if(sum > max1)
				max1 = sum;
		}
		
		sum = 0;
		for(int j = 2; j < 6; j++){
			sum += get_max_char_value(bord[j][i]);
		}
		if(sum == 20) return -20;
		if(sum < 20){
			if(sum > max1)
				max1 = sum;
		}
		
		//A.I.
		sum = 0;
		for(int j = 0; j < 4; j++){
			sum += get_min_char_value(bord[j][i]);
		}
		if(sum == 20) return 20;
		if(sum < 20){
			if(sum > max2)
				max2 = sum;
		}
		sum = 0;
		for(int j = 1; j < 5; j++){
			sum += get_min_char_value(bord[j][i]);
		}
		if(sum == 20) return 20;
		if(sum < 20){
			if(sum > max2)
				max2 = sum;
		}
		sum = 0;
		for(int j = 2; j < 6; j++){
			sum += get_min_char_value(bord[j][i]);
		}
		if(sum == 20) return 20;
		if(sum < 20){
			if(sum > max2)
				max2 = sum;
		}
	
	}
	//Huamn
	int sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_max_char_value(bord[i][i + 3]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_max_char_value(bord[i][i + 2]);
	} 
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_max_char_value(bord[i][i + 2]);
	} 
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	/////////////////////////////////////////////
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_max_char_value(bord[i][i + 1]);
	} 
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_max_char_value(bord[i][i + 1]);
	} 
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_max_char_value(bord[i][i + 1]);
	} 
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	///////////////////////////////////////////////
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_max_char_value(bord[i][i]);
	}
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_max_char_value(bord[i][i]);
	} 
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_max_char_value(bord[i][i]);
	} 
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//////////////////////////////////////////////////////
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_max_char_value(bord[i][i - 1]);
	}
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_max_char_value(bord[i][i - 1]);
	}
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_min_char_value(bord[i][i - 2]);
	} 
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	
	//A.I.
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_min_char_value(bord[i][i + 3]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_min_char_value(bord[i][i + 2]);
	} 
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_min_char_value(bord[i][i + 2]);
	} 
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	//////////////////////////////////////////////
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_min_char_value(bord[i][i + 1]);
	} 
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_min_char_value(bord[i][i + 1]);
	} 
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_min_char_value(bord[i][i + 1]);
	} 
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	//////////////////////////////////////////////
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_min_char_value(bord[i][i]);
	}
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_min_char_value(bord[i][i]);
	} 
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_min_char_value(bord[i][i]);
	} 
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	/////////////////////////////////////////////
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_min_char_value(bord[i][i - 1]);
	}
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_min_char_value(bord[i][i - 1]);
	}
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_min_char_value(bord[i][i - 2]);
	} 
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	//Huamn
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_max_char_value(bord[3 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//A.I.
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_min_char_value(bord[3 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	////////////////////////////////////////////////////////////
	//Human
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_max_char_value(bord[4 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_max_char_value(bord[4 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//A.I.
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_min_char_value(bord[4 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_min_char_value(bord[4 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	//////////////////////////////////////////////////////
	//Human
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_max_char_value(bord[5 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//A.I.
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_max_char_value(bord[5 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//Human
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_max_char_value(bord[5 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//A.I.
	sum = 0;
	for(int i = 0; i < 4; i++){
		sum += get_min_char_value(bord[5 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_min_char_value(bord[5 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_min_char_value(bord[5 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	///////////////////////////////////////////////////////////
	//Human
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_max_char_value(bord[6 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_max_char_value(bord[6 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	sum = 0;
	for(int i = 3; i < 7; i++){
		sum += get_max_char_value(bord[6 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//A.I.
	sum = 0;
	for(int i = 1; i < 5; i++){
		sum += get_min_char_value(bord[6 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_min_char_value(bord[6 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 3; i < 7; i++){
		sum += get_min_char_value(bord[6 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	/////////////////////////////////////////////////////
	//Human
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_max_char_value(bord[7 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	sum = 0;
	for(int i = 3; i < 7; i++){
		sum += get_max_char_value(bord[7 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//A.I.
	sum = 0;
	for(int i = 2; i < 6; i++){
		sum += get_min_char_value(bord[7 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	sum = 0;
	for(int i = 3; i < 7; i++){
		sum += get_min_char_value(bord[7 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	/////////////////////////////////////////////////////////
	//Human
	sum = 0;
	for(int i = 3; i < 7; i++){
		sum += get_max_char_value(bord[8 - i][i]);
	} 
	
	if(sum == 20) return -20;
	if(sum < 20){
		if(sum > max1)
			max1 = sum;
	}
	//A.I.
	sum = 0;
	for(int i = 3; i < 7; i++){
		sum += get_min_char_value(bord[8 - i][i]);
	} 
	
	if(sum == 20) return 20;
	if(sum < 20){
		if(sum > max2)
			max2 = sum;
	}
	
	if(max1 <= max2) return max2;
	else return -max1;	
						
	for(int i = 0; i < 3; i++){
		if(lavel[i] >= 0) return 100;
	}	
	return 0;
}
void state::update(int i, char player){
	
	if(lavel[i] > -1){
		bord[lavel[i]][i] = player;
		lavel[i] -= 1;
	}
}

state get_value(int agent, state current_state, int d){
	current_state.steps += 1;
	int leaf = current_state.get_minimax();
	if(current_state.steps > 4){
		current_state.value = leaf;
		return current_state;
	}
	d++;
	if(leaf == 20 || leaf == -20){
		current_state.value = leaf;
		return current_state;
	}else{
		if(agent == 1){
			int min = 1000;
			state min_state;
			
			for(int i = 0; i < 7; i++){
				if(current_state.lavel[i] < 0) continue;
				state current_state2 = current_state;
				
				current_state2.update(i, '0');
				state tmp = get_value(0, current_state2, d);
				if(tmp.value <= min){
					if(min == tmp.value && tmp.steps < min_state.steps){
						min = tmp.value;
						min_state = current_state2;
						min_state.steps = tmp.steps;
						min_state.value = tmp.value;
						if(tmp.steps == 1) break;
					}else if(min > tmp.value){
						min = tmp.value;
						min_state = current_state2;
						min_state.steps = tmp.steps;
						min_state.value = tmp.value;
						if(min == -20) break;
					}
				}
			}
			return min_state;
		}else{
			int max = -1000;
			state max_state;
			for(int i = 0; i < 7; i++){
				if(current_state.lavel[i] < 0) continue;
				state current_state2 = current_state;
				current_state2.update(i, '#');
				
				state tmp = get_value(1, current_state2, d);
				if(tmp.value >= max){
					if(max == tmp.value && tmp.steps < max_state.steps){
						max = tmp.value;
						max_state = current_state2;
						max_state.steps = tmp.steps;
						max_state.value = tmp.value;
						if(tmp.steps == 1) break;
					}else if(max < tmp.value){
						max = tmp.value;
						max_state = current_state2;
						max_state.steps = tmp.steps;
						max_state.value = tmp.value;
						if(max == 20) break;
					}
				}
			}
			return max_state;
		}
	}
}
