# 공 튀기기(원본)
* Style
```
<style>
  canvas {
    background: #eee;
  }; 
</style>
```

* Body(canvas )
```
<body>
  <canvas id="myCanvas" width="480" height="320"></canvas>
</body>
```

* Script(변수)
```
<script>
  var canvas = document.getElementById("myCanvas");
  var ctx = canvas.getContext("2d");
  var ballRadius = 10;
  var x = canvas.width/2;
  var y = canvas.height-30;
  var dx = 2;
  var dy = -2;
</script>
```

* Script(drawBall 함수)
```
<script>
  function drawBall() {
    ctx.beginPath();
    ctx.arc(x, y, ballRadius, 0, Math.PI*2);
    ctx.fillStyle = "#0095DD";
    ctx.fill();
    ctx.closePath();
  }
</script>
```

* Script(draw 함수)
```
<script>
  function draw() {
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawBall();
    
    if(x + dx > canvas.width-ballRadius || x + dx < ballRadius) {
      dx = -dx;
    }
    if(y + dy > canvas.height-ballRadius || y + dy < ballRadius) {
      dy = -dy;
    }
    
    x += dx;
    y += dy;
  }
</script>
```

* Script(setInterval 함수)
```
<script>
  setInterval(draw, 10);
</script>
``` 

# 오래 공 튀기기
* title
```
<title>
  오래 공 튀기기 게임
</title>
``` 

* style
```
<style>
	h1{
		position: absolute;
		top : 5%;
		left: 50%;
		transform: translate(-50%,0%);
	}
        
	div{
		position: absolute;
		bottom: 40%;
           	left: 50%;
		transform: translate(-50%,0%);
		text-align: center;
		color: black;
		font-weight: bold;	
	}
	
        canvas {
            background: #eee;
            position: absolute;
	    top : 5%;
            left: 50%;
	    transform: translate(-50%,0%);
        }	
</style>
``` 

* Body(canvas, h1, div, p, form, select, option, button, br 태그)
```
<body>
  <canvas id="GamePlay" width="1920" height="1080"></canvas>
  <h1 onload="startscore()" id="score" style="display: none" >
  	0
  </h1>
  <div id="menu">
		<p style="font-size :40px; margin: 10px;">Mode</p>
		<form >
			<select onchange="modevalue(this)">
				<option>모드 선택</option>
				<option value="T">Time</option>
				<option value="H">Hit</option>
			</select>
		</form>
		
    	<P>Ball Speed <input id="BallSpeed" type="number" max="5" min="2" placeholder="2"></P> 
    	<P>Ball Size <input id="Ballsize" type="number" max="20" min="10" placeholder="20"></P>
    	<P>ball count <input id="balls" type="number" max="3" min="1" placeholder="1"></P> 
    	<button id="setting" style="padding: 10px 40px; font-size: 20px;">setting</button>
		<br>
		<br>
    	<button id="start"style="padding: 12px 50px; font-size: 20px;">start</button>
	</div>
</body>
```

* script(canvas 설정 변수)
```
<script>
// 캔버스 설정 변수
    const canvas = document.getElementById("GamePlay"); 
    const ctx = canvas.getContext("2d")
    let HitEnd = false // 점수 선택 변수
    let tmp // 게임 애니메이션 효과 변수
    let tmp1 // 메뉴 애니메이션 효과 변수
    let tmp2 // 끝 애니메이션 효과 변수
</script>
```

* script(menu canvas화면에 사용하는 변수)
```
<script>
// 메뉴 볼 크기 변수
	let menuballr1 = 40
	let menuballr2 = 40
	let menuballr3 = 40
	let menuballr4 = 40
	let menuballr5 = 40
	// 메뉴 볼 좌표 밑 속도
	let menux1 = canvas.width / 2 // 공의 좌표 x
	let menuy1 = canvas.height - 100 // 공의 좌표 y
	let menudx1 = 7 // x속도
	let menudy1 = -7// y 속도

	let menux2 = canvas.width / 2 + 200 // 공의 좌표 x
	let menuy2 = canvas.height - 200 // 공의 좌표 y
	let menudx2 = 7 // x속도
	let menudy2 = -7// y 속도

	let menux3 = canvas.width / 2 + 400// 공의 좌표 x
	let menuy3 = canvas.height - 400 // 공의 좌표 y
	let menudx3= 7 // x속도
	let menudy3 = -7// y 속도

	let menux4 = canvas.width / 2 - 200// 공의 좌표 x
	let menuy4 = canvas.height - 500 // 공의 좌표 y
	let menudx4 = 7 // x속도
	let menudy4 = -7// y 속도

	let menux5 = canvas.width / 2 - 400// 공의 좌표 x
	let menuy5 = canvas.height - 600 // 공의 좌표 y
	let menudx5 = 7 // x속도
	let menudy5 = -7// y 속도
</script>
```

* script(Game canvas화면에 사용하는 변수)
```
<script>
// 게임 볼 크기, 좌표, 속도 변수
    	let ballRadius = 20 // 볼크기
	let ballRadius1 = 20 // 볼크기
	let ballRadius2 = 20 // 볼크기
    	let x = canvas.width / 2 // 공의 좌표 x
    	let y = canvas.height - 200 // 공의 좌표 y
    	let dx = 1 // x속도
    	let dy = -1// y 속도

	let x1= canvas.width / 2  + 100// 공의 좌표 x
    	let y1 = canvas.height - 600 // 공의 좌표 y
    	let dx1 = 1 // x속도
    	let dy1 = -1// y 속도

	let x2 = canvas.width / 2 - 100 // 공의 좌표 x
    	let y2 = canvas.height - 400 // 공의 좌표 y
    	let dx2 = 1 // x속도
   	let dy2 = -1// y 속도

    	let ballSpeed = 2 // 공속도
	let ballSpeed1 = 2 // 공속도
	let ballSpeed2 = 2 // 공속도

	// 볼 갯수 체크 변수
	let b = true
	let b1 = false
	let b2 = false

    	// palyer 크기및 좌표 변수
	const PlayerH = 20 // 플레이어 세로크기
	const PlayerW = 80 // 플레이어 가로크기
	let playerX = (canvas.width - PlayerW) / 2 //플레이어 x위치
    
	// key event
	let RP = false
	let LP = false

	//Menu 설정 변수
	let start = document.getElementById("start");
	let setting = document.getElementById("setting");
	let bspd = document.getElementById("BallSpeed");
	let bsz = document.getElementById("Ballsize");
	let bc = document.getElementById("balls");

	// 점수
	let timerId;
	let time = 0;
	const score = document.getElementById("score");
	let hitscore = score.innerText;
	//메뉴 셋팅 태그 변수
	let div = document.getElementById("menu")
	let mode;
</script>
```

* script(modevalue 람다함수)
```
<script>
	// 점수 얻는 방법의 변수를 가져오는 함수
	const modevalue = (target) =>{
		mode = target.value;
	}
</script>
```

* script(keydownHand, keyupHand 함수)
```
<script>
	//키보드에서 눌렸을 때 일어나는 함수
    	function keydownHand(event) {
	    if (event.keyCode === 39) {
		    RP = true
	    }
	    else if (event.keyCode === 37) {
		    LP = true
	    }
    	}

	//키보드에서 안 눌렸을 때 일어나는 함수
	function keyupHand(event) {
		if (event.keyCode === 39) {
			RP = false
		}
		else if (event.keyCode === 37) {
			LP = false
		}
	}
</script>
```

* script(setting.onclick 이벤트)
```
<script>
// 셋팅 이벤트
	setting.onclick = () =>{
		if(bspd.value != '' ){
			ballSpeed = bspd.value
			ballSpeed1 = bspd.value
			ballSpeed2 = bspd.value
		}
		if(bsz.value != '' ){
			ballRadius = bsz.value
			ballRadius1 = bsz.value
			ballRadius2 = bsz.value
		}
		if(bc.value != '' ){
			if(bc.value == 1){
				b = true
			}
			if(bc.value == 2){
				b = true
				b1 = true
			}
		if(bc.value == 3){
			b = true;
			b1 = true
			b2 = true
		}

	}
}
</script>
```

* script(menu canvas에서 사용하는 공을 생성하는 함수)
```
<script>
//메뉴 공
function menudrawBall1() {
	ctx.beginPath()
	ctx.arc(menux1, menuy1, menuballr1, 0, Math.PI * 2, false)
	ctx.fillStyle = "red"
	ctx.fill()
	ctx.closePath()
}
function menudrawBall2() {
	ctx.beginPath()
	ctx.arc(menux2, menuy2, menuballr2, 0, Math.PI * 2, false)
	ctx.fillStyle = "yellow"
	ctx.fill()
	ctx.closePath()
}
function menudrawBall3() {
	ctx.beginPath()
	ctx.arc(menux3, menuy3, menuballr3, 0, Math.PI * 2, false)
	ctx.fillStyle = "green"
	ctx.fill()
	ctx.closePath()
}
function menudrawBall4() {
	ctx.beginPath()
	ctx.arc(menux4, menuy4, menuballr4, 0, Math.PI * 2, false)
	ctx.fillStyle = "blue"
	ctx.fill()
	ctx.closePath()
}
function menudrawBall5() {
	ctx.beginPath()
	ctx.arc(menux5, menuy5, menuballr5, 0, Math.PI * 2, false)
	ctx.fillStyle = "purple"
	ctx.fill()
	ctx.closePath()
}
</script>
```

* script(menudraw 함수, 애니메이션 효과 )
```
<script>
// 메뉴 캔버스
function manudraw(){
	ctx.clearRect(0, 0, canvas.width, canvas.height);
    menudrawBall1();
	menudrawBall2();
	menudrawBall3();
	menudrawBall4();
	menudrawBall5();
	ctx.fillStyle = "black"; //폰트색
	ctx.textAlign = "center"; // 폰트 위치
	ctx.font = "italic bold 50px Arial, sans-serif"; // 폰트 스타일
	ctx.fillText("오래 공 튀기기 게임", canvas.width/2, canvas.height /2 - 300);
	ctx.font = "italic bold 30px Arial, sans-serif"; // 폰트 스타일
	ctx.fillText("게임 설명", canvas.width/2, canvas.height /2 + 190);
	ctx.fillText("1. 화면 크기(1920 X 1080)으로 플레이해주세요.", canvas.width/2, canvas.height /2 + 240);
	ctx.fillText("2. 밑에 입력 칸예 원하는 설정을 한 후 setting을 클릭해주세요.", canvas.width/2, canvas.height /2 + 280);
	ctx.fillText("3. 준비가 됐으면 start를 클릭해주세요.", canvas.width/2, canvas.height /2 + 320);
	ctx.fillText("4. 그 후 공이 땅에 떨어지지 않게 오래 버티면 됩니다.", canvas.width/2, canvas.height /2 + 360);
	ctx.fillText("TIP : 높은 점수를 얻고 싶으면 공의 갯수를 늘리거나 공의 속도를 올려주세요", canvas.width/2, canvas.height /2 + 500);
    
	if(menux1 + menudx1 > canvas.width-menuballr1 || menux1 + menudx1 < menuballr1) {
        menudx1 = -menudx1;
    }
    if(menuy1 + menudy1 > canvas.height-menuballr1 || menuy1 + menudy1 < menuballr1) {
        menudy1 = -menudy1;
    }

	if(menux2 + menudx2 > canvas.width-menuballr2 || menux2 + menudx2 < menuballr2) {
        menudx2 = -menudx2;
    }
    if(menuy2 + menudy2 > canvas.height-menuballr2 || menuy2 + menudy2 < menuballr2) {
        menudy2 = -menudy2;
    }

	if(menux3 + menudx3 > canvas.width-menuballr3 || menux3 + menudx3 < menuballr3) {
        menudx3 = -menudx3;
    }
    if(menuy3 + menudy3 > canvas.height-menuballr3 || menuy3 + menudy3 < menuballr3) {
        menudy3 = -menudy3;
    }

	if(menux4 + menudx4 > canvas.width-menuballr4 || menux4 + menudx4 < menuballr4) {
        menudx4 = -menudx4;
    }
    if(menuy4 + menudy4 > canvas.height-menuballr4 || menuy4 + menudy4 < menuballr4) {
        menudy4 = -menudy4;
    }
	if(menux5 + menudx5 > canvas.width-menuballr5 || menux5 + menudx5 < menuballr5) {
        menudx5 = -menudx5;
    }
    if(menuy5 + menudy5 > canvas.height-menuballr5 || menuy5 + menudy5 < menuballr5) {
        menudy5 = -menudy5;
    }

	menux1 += menudx1;
    menuy1 += menudy1;

	menux2 += menudx2;
    menuy2 += menudy2;
	
	menux3 += menudx3;
    menuy3 += menudy3;

	menux4 += menudx4;
    menuy4 += menudy4;

	menux5 += menudx5;
    menuy5 += menudy5;
}
// 메뉴 시작
tmp1 = setInterval(manudraw, 10)
</script>
```

* script(drawPlayer 함수, drawBall 함수들)
```
<script>
//플레이어
function drawPlayer() {
	ctx.beginPath()
	ctx.rect(playerX, canvas.height - PlayerH, PlayerW, PlayerH)
	ctx.fillStyle = "skyblue"
	ctx.fill()
	ctx.closePath()
}

//게임 공
function drawBall() {
	ctx.beginPath()
	ctx.arc(x, y, ballRadius, 0, Math.PI * 2, false)
	ctx.fillStyle = "lightgreen"
	ctx.fill()
	ctx.closePath()
}
function drawBall1() {
	ctx.beginPath()
	ctx.arc(x1, y1, ballRadius, 0, Math.PI * 2, false)
	ctx.fillStyle = "Skyblue"
	ctx.fill()
	ctx.closePath()
}
function drawBall2() {
	ctx.beginPath()
	ctx.arc(x2, y2, ballRadius, 0, Math.PI * 2, false)
	ctx.fillStyle = "red"
	ctx.fill()
	ctx.closePath()
}
</script>
```

* script(draw 함수, 시간으로 점수얻는 게임)
```
<script>
//time게임 캔버스
function draw() {
	ctx.clearRect(0, 0, canvas.width, canvas.height)
	if(b == true){
		drawBall() // 공 생성
		x += dx * ballSpeed
		y += dy * ballSpeed
	}
	if(b1 == true){
		drawBall1() // 공 생성
		x1 += dx1 * ballSpeed1
		y1 += dy1 * ballSpeed1
	}
	if(b2 == true){
		drawBall2() // 공 생성
		x2 += dx2 * ballSpeed2
		y2 += dy2 * ballSpeed2
	}
	drawPlayer() // 플레이어 생성
	
	// 충돌 체크
	if (y + dy < ballRadius) {
		dy = -dy
	} else if (y + dy > canvas.height - ballRadius) {
		stopscore()
		score.style.display='none'
		clearInterval(tmp)
		tmp2 = setInterval(ENDdraw, 10)
	} else if (y + dy > canvas.height - ballRadius - PlayerH &&
				x + dx > playerX && x + dx < playerX + PlayerW) {
		dy = -dy
	}
	if (x + dx > canvas.width - ballRadius || x + dx < ballRadius) {
		dx = -dx
	}

	if (y1 + dy1 < ballRadius1) {
		dy1 = -dy1
	} else if (y1+ dy1 > canvas.height - ballRadius1) {
		stopscore()
		score.style.display='none'
		clearInterval(tmp)
		tmp2 = setInterval(ENDdraw, 10)

	} else if (y1 + dy1 > canvas.height - ballRadius1 - PlayerH &&
				x1 + dx1 > playerX && x1 + dx1 < playerX + PlayerW) {
		dy1 = -dy1
	}
	if (x1 + dx1> canvas.width - ballRadius1 || x1 + dx1 < ballRadius1) {
		dx1 = -dx1
	}

	if (y2 + dy2 < ballRadius2) {
		dy2= -dy2
	} else if (y2 + dy2 > canvas.height - ballRadius2) {
		stopscore()
		score.style.display='none'
		clearInterval(tmp)
		tmp2 = setInterval(ENDdraw, 10)

	} else if (y2 + dy2 > canvas.height - ballRadius2 - PlayerH &&
				x2 + dx2 > playerX && x2 + dx2 < playerX + PlayerW) {
		dy2 = -dy2
	}
	if (x2 + dx2 > canvas.width - ballRadius2 || x2 + dx2 < ballRadius2) {
		dx2 = -dx2
	}
	
	// 키 체크
	if (RP && playerX < canvas.width - PlayerW) {
		playerX += 5
	}
	if (LP && playerX > 0) {
		playerX -= 5
	}

}

</script>
```

* script(Hitdraw 함수, 충돌 시 점수얻는 게임)
```
<script>
//Hit게임 캔버스
function Hitdraw() {
	ctx.clearRect(0, 0, canvas.width, canvas.height)
	if(b == true){
		drawBall() // 공 생성
		x += dx * ballSpeed
		y += dy * ballSpeed
	}
	if(b1 == true){
		drawBall1() // 공 생성
		x1 += dx1 * ballSpeed1
		y1 += dy1 * ballSpeed1
	}
	if(b2 == true){
		drawBall2() // 공 생성
		x2 += dx2 * ballSpeed2
		y2 += dy2 * ballSpeed2
	}
	drawPlayer() // 플레이어 생성

	// 충돌 체크
	if(HitEnd == false){
		if (y + dy < ballRadius) {
		dy = -dy
		hitscore = parseInt(hitscore) + 1
		score.innerText = hitscore
	} else if (y + dy > canvas.height - ballRadius) {
		HitEnd = true
		score.style.display='none'
		clearInterval(tmp)
		tmp2 = setInterval(ENDdraw, 10)
	} else if (y + dy > canvas.height - ballRadius - PlayerH &&
				x + dx > playerX && x + dx < playerX + PlayerW) {
		dy = -dy
		hitscore = parseInt(hitscore) + 1
		score.innerText = hitscore
	}
	if (x + dx > canvas.width - ballRadius || x + dx < ballRadius) {
		dx = -dx
		hitscore = parseInt(hitscore) + 1
		score.innerText = hitscore
	}

	if (y1 + dy1 < ballRadius1) {
		dy1 = -dy1
		hitscore = parseInt(hitscore) + 1
		score.innerText = hitscore
	} else if (y1+ dy1 > canvas.height - ballRadius1) {
		HitEnd = true
		score.style.display='none'
		clearInterval(tmp)
		tmp2 = setInterval(ENDdraw, 10)

	} else if (y1 + dy1 > canvas.height - ballRadius1 - PlayerH &&
				x1 + dx1 > playerX && x1 + dx1 < playerX + PlayerW) {
		dy1 = -dy1
		hitscore = parseInt(hitscore) + 1
		score.innerText = hitscore
	}
	if (x1 + dx1> canvas.width - ballRadius1 || x1 + dx1 < ballRadius1) {
		dx1 = -dx1
		hitscor
		
		e = parseInt(hitscore) + 1
		score.innerText = hitscore
	}

	if (y2 + dy2 < ballRadius2) {
		dy2= -dy2
		hitscore = parseInt(hitscore) + 1
		score.innerText = hitscore
	} else if (y2 + dy2 > canvas.height - ballRadius2) {
		HitEnd = true
		score.style.display='none'
		clearInterval(tmp)
		tmp2 = setInterval(ENDdraw, 10)
	} else if (y2 + dy2 > canvas.height - ballRadius2 - PlayerH &&
				x2 + dx2 > playerX && x2 + dx2 < playerX + PlayerW) {
		dy2 = -dy2
		hitscore = parseInt(hitscore) + 1
		score.innerText = hitscore
	}
	if (x2 + dx2 > canvas.width - ballRadius2 || x2 + dx2 < ballRadius2) {
		dx2 = -dx2
		hitscore = parseInt(hitscore) + 1
		score.innerText = hitscore
	}

	}
	
	
	// 키 체크
	if (RP && playerX < canvas.width - PlayerW) {
		playerX += 5
	}
	if (LP && playerX > 0) {
		playerX -= 5
	}

}
</script>
```

* script(printTime 함수)
```
<script>
// 점수 표현
function printTime() {
    time++;
    score.innerText = time;
}
</script>
```

* script(startscore 함수)
```
<script>
//스코어 시작 - 재귀호출로 반복실행, 각 설정에 따른 스코어 상승속도 조절
function startscore() {
    printTime();
	if(b2 == true && b1 == true && b == true){
		if(ballSpeed == 2){
			timerId = setTimeout(startscore, 600);
		}else if(ballSpeed == 3){
			timerId = setTimeout(startscore, 566);
		}else if(ballSpeed == 4){
			timerId = setTimeout(startscore, 533);
		}else if(ballSpeed == 5){
			timerId = setTimeout(startscore, 500);
		}

	}else if(b1 == true && b == true){
		if(ballSpeed == 2){
			timerId = setTimeout(startscore, 800);
		}else if(ballSpeed == 3){
			timerId = setTimeout(startscore, 766);
		}else if(ballSpeed == 4){
			timerId = setTimeout(startscore, 733);
		}else if(ballSpeed == 5){
			timerId = setTimeout(startscore, 700);
		}
	}else if(b == true){
		if(ballSpeed == 2){
			timerId = setTimeout(startscore, 1000);
		}else if(ballSpeed == 3){
			timerId = setTimeout(startscore, 966);
		}else if(ballSpeed == 4){
			timerId = setTimeout(startscore, 933);
		}else if(ballSpeed == 5){
			timerId = setTimeout(startscore, 900);
		}
	}

}
</script>
```

* script(stopscore 함수)
```
<script>
//스코어 상승 중지
function stopscore() {
    if (timerId != null) {
        clearTimeout(timerId);
    }
}
</script>
```

* script(ENDdraw 함수)
```
<script>
function ENDdraw(){
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	ctx.fillStyle = "black"; //폰트색
	ctx.textAlign = "center"; // 폰트 위치
	ctx.font = "italic bold 50px Arial, sans-serif"; // 폰트 스타일
	ctx.fillText("GAME OVER", canvas.width/2, canvas.height /2);
	ctx.font = "italic bold 35px Arial, sans-serif"; // 폰트 스타일
	ctx.fillText("SCORE : "+score.innerText, canvas.width/2, canvas.height /2 + 50);

}
</script>
```

* script(keydown, keyup, start.onclick 이벤트)
```
<script>
document.addEventListener("keydown", keydownHand, false)
document.addEventListener("keyup", keyupHand, false)
start.onclick = () =>{
	div.style.display='none' // 시작 후 셋팅 메뉴 안보이게 시작 
	document.getElementById('score').style.display = 'block' // 스코어 보이게
	clearInterval(tmp1) // 메뉴 캔버스 멈추기
	console.log(mode)
	if(mode == 'T'){
		startscore() // 시작 후 스코어가 화면에 나타나고 스코어 상승 시작
		tmp = setInterval(draw, 10) // 게임 캔버스 시작
	}else{
		tmp = setInterval(Hitdraw, 10) // 게임 캔버스 시작
	}
	
}
</script>
```

# 출처 및 참조
* [Original Code](https://developer.mozilla.org/ko/docs/Games/Tutorials/2D_Breakout_game_pure_JavaScript/Bounce_off_the_walls)
* [Position](https://developer.mozilla.org/en-US/docs/Web/CSS/position)
* [Animation Effect](https://developer.mozilla.org/en-US/docs/Web/API/setInterval)
* [Canvas](https://developer.mozilla.org/ko/docs/Web/API/Canvas_API/Tutorial/Basic_usage)
* [Canvas Text](https://developer.mozilla.org/ko/docs/Web/API/Canvas_API/Tutorial/Drawing_text)
* [Flowing Time Effect](https://stickode.tistory.com/230)
* [Event Listener](https://developer.mozilla.org/ko/docs/Web/API/EventTarget/addEventListener)
