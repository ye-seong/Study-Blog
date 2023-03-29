using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Video;

public class Billboard : MonoBehaviour
{
    [SerializeField] private Transform targetTr = null;

    private AnchorPivotJoint apj = null;
    private Screen screen = null;

    //Screen Play Distance
    private readonly float scrPlayDist = 20f;

    private void Awake()
    {
        //GetComponentInChildren<Billboard>(); //Billboard자식에게서 컴포넌트를 가져옴
        //GetComponentsInChildren<Billboard>(); //Billboard자식'들'에게서 컴포넌트를 가져옴
        //transform.GetChiled; //자식에게서 transform을 가져옴
        //GameObject.Find //gameobject찾아옴(모든 gameobject를 검사해야해서... 좀 비추?)
        apj = GetComponentInChildren<AnchorPivotJoint>();
        screen = GetComponentInChildren<Screen>();
    }

    private void Start()
    {
        //방법1: 자료형으로 들고옴(제일많이씀)
        VideoClip clip = Resources.Load<VideoClip>("Videos\\imase_NIGHT_DANCER");
        /*
        //방법2: 안정적으로 형변환함
        clip = Resources.Load("Videos\\imase_NIGHT_DANCER") as VideoClip;
        //방법3: 명시적형변환방법
        clip = (VideoClip)Resources.Load("Videos\\imase_NIGHT_DANCER");
        */

        screen.SetVideoClip(clip);
    }

    private void Update()
    {
        float angleRad = CalcAngleToTarget();
        apj.Yaw((90f + 180f) - (angleRad * Mathf.Rad2Deg)); //90f + 180f 는 각도를 보정해준거임

        float dist = CalcDistanceWithTarget();
        if (dist < scrPlayDist) screen.Play();
        else screen.Pause();

        DebugDistance();
    }

    private float CalcAngleToTarget()
    {
        //방향벡터 구하기
        Vector3 dirToTarget = targetTr.position - transform.position; //target으로 향하는 방향
        dirToTarget.Normalize();

        //길이가 1인 벡터를 만들기: 벡터의 각 성분을 벡터의 길이로 나눈다.

        //Atan(y / x);
        return Mathf.Atan2(dirToTarget.z, dirToTarget.x); //각도구하기(Atan2)
    }

    private float CalcDistanceWithTarget()
    {
        Vector3 dirToTarget = targetTr.position - transform.position;
        //방법1 (magnitude는 거리)
        float dist = dirToTarget.magnitude; 
        //방법2
        dist = Vector3.Distance(targetTr.position, transform.position);

        return dist;
    }

    //비디오가 재생하고 있을 거리에선 빨간선, 아닐땐 노란선을 나타냄
    private void DebugDistance()
    {
        Vector3 dirTotarget = targetTr.position - transform.position;

        Color color = Color.white;
        if (scrPlayDist < dirTotarget.magnitude)
            color = Color.yellow;
        else
            color = Color.red;

        Debug.DrawLine(transform.position, targetTr.position, color);
    }
}
