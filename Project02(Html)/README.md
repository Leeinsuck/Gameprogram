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


# 출처
[원본소스링크](https://developer.mozilla.org/ko/docs/Games/Tutorials/2D_Breakout_game_pure_JavaScript/Bounce_off_the_walls)
