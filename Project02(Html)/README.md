# 공 튀기기(원본)
* Style(canvas 배경색 색 코드 #eee)
```
<style>
  canvas {
    background: #eee;
  }; 
</style>
```

* Body(canvas의 480 x 320 크기)
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

* Script(draw 함수)
```
<script>
  setInterval(draw, 10);
</script>
``` 

# 오래 공 튀기기

# 출처
[원본소스링크](https://developer.mozilla.org/ko/docs/Games/Tutorials/2D_Breakout_game_pure_JavaScript/Bounce_off_the_walls)
