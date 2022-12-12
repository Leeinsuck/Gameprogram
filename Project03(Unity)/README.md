# 자동차 게임
* Player - Script
```
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Player : MonoBehaviour
{

    public float power = 50f; // 바퀴를 회전시킬 힘
    public float rot = 15f; // 바퀴의 회전 각도
    Rigidbody rb;
    public WheelCollider[] wheels = new WheelCollider[4];
    // 차량 모델의 바퀴 부분 4개
    GameObject[] wheelMesh = new GameObject[4];
    
 

    public int currentSpeed; // 현재 속도


    public float decSpeed = 100f;// 감속량


    public int Maxoil = 2000; // 기름양

    public GameObject body; // 색 변경 오브젝트

    public Material white;
    public Material black;
    public Material blue;
    public Material green;
    public Material gold;

    public AudioSource StarAudio;
    public AudioSource RidingAudio;

    public Text SpeedCount; // UI 속도 Text
    public Text oilCount; // UI 기름 Text


    

    void Start()
    {
        // 바퀴 모델을 태그를 통해서 찾아온다.(차량이 변경되더라도 자동으로 찾기위해서)
        wheelMesh = GameObject.FindGameObjectsWithTag("WheelMesh");
        StarAudio.Play();
        RidingAudio.Play();
        RidingAudio.loop=true;

        for (int i = 0; i < wheelMesh.Length; i++)
        {	// 휠콜라이더의 위치를 바퀴메쉬의 위치로 각각 이동시킨다.
            wheels[i].transform.position = wheelMesh[i].transform.position;
        }
        rb = GetComponent<Rigidbody>();
        // 무게 중심을 y축 아래방향으로 낮춘다.
        rb.centerOfMass = new Vector3(0, -1, 0);
    }

    void OnTriggerEnter(Collider other)
    {
        if(other.tag == "oil")
        {
            Maxoil = Maxoil + 500;
            other.gameObject.SetActive(false);
            
        }
    }

    private void FixedUpdate()
    {
        currentSpeed = (int)rb.velocity.magnitude;
        SpeedCount.text = currentSpeed.ToString();
        oilCount.text = Maxoil.ToString();
        // 차색상변경
        if (Input.GetKey(KeyCode.Keypad1))
        {
            body.GetComponent<MeshRenderer>().material=white;
        }else if (Input.GetKey(KeyCode.Keypad2))
        {
            body.GetComponent<MeshRenderer>().material = black;
        }else if (Input.GetKey(KeyCode.Keypad3))
        {
            body.GetComponent<MeshRenderer>().material = blue;
        }else if (Input.GetKey(KeyCode.Keypad4))
        {
            body.GetComponent<MeshRenderer>().material = green;
        }
        else if (Input.GetKey(KeyCode.Keypad5))
        {
            body.GetComponent<MeshRenderer>().material = gold;
        }

        for (int i = 0; i < wheels.Length; i++)
        {
          
            
            //기름이 없으면 플레이어 작동불가
            if (Maxoil <= 0)
            {
                wheels[i].brakeTorque = decSpeed;
                RidingAudio.loop = false;
                RidingAudio.Stop();
            }
            else
            {
                wheels[i].brakeTorque = 0;
                //게임 시작 후 서서히 기름 소모
                Maxoil = Maxoil - 1;

                // for문을 통해서 휠콜라이더 전체를 Vertical 입력에 따라서 power만큼의 힘으로 움직이게한다.
                wheels[i].motorTorque = Input.GetAxis("Vertical") * power;
                //속도 감속
                if (!Input.GetButton("Vertical"))
                {
                    wheels[i].brakeTorque = decSpeed;
                }
                else
                {
                    wheels[i].brakeTorque = 0;
                }
            }
        }
        for (int i = 0; i < 2; i++)
        {
            // 앞바퀴만 각도전환이 되어야하므로 for문을 앞바퀴만 해당되도록 설정한다.
            wheels[i].steerAngle = -Input.GetAxis("Horizontal") * rot;
        }
    }

}

```

* Oil - Script
```
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Oil : MonoBehaviour
{
    public float rorareSpeed; // 회전속도
    void Update()
    {
        transform.Rotate(Vector3.up * rorareSpeed * Time.deltaTime, Space.World);
    }
}
```

* Cam - Script
```
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cam : MonoBehaviour
{
    public GameObject MainCam;
    public GameObject PlayerCam;

    void Start()
    {
        
        PlayerCam.SetActive(false); //자동차 시점 오프
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Q))
        {
            MainCam.SetActive(true); //전체 시점 온
            PlayerCam.SetActive(false); //자동차 시점 오프
        }else if (Input.GetKey(KeyCode.W))
        {
            MainCam.SetActive(false); //전체 시점 오프
            PlayerCam.SetActive(true); //자동차 시점 온
        }
    }
}

```



# 출처 및 참조
* [원본](https://www.youtube.com/watch?v=pTc1dakebow)
* [휠 콜라이더 기본 세팅](https://coding-of-today.tistory.com/128)
* [휠 콜라이더 움직임 구현](https://coding-of-today.tistory.com/130)
* [카메라 온오프](https://artiper.tistory.com/106)
* [키 코드](https://wergia.tistory.com/211)
* [속도 감속](https://micropilot.tistory.com/2656)
* [오디오](https://202psj.tistory.com/1312)
* [각각의 업데이트](http://developug.blogspot.com/2014/09/update-fixedupdate-lateupdate.html)
* [구조체+맵](https://assetstore.unity.com/packages/3d/environments/industrial/rpg-fps-game-assets-for-pc-mobile-industrial-set-v2-0-86679)
* [사운드](https://assetstore.unity.com/packages/audio/sound-fx/transportation/i6-german-free-engine-sound-pack-106037)
* [자동차](https://assetstore.unity.com/packages/3d/vehicles/land/hq-racing-car-model-no-1203-139221)
