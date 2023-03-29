using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//[ExecuteInEditMode] //이걸 붙이면 실행모드가 아닌 편집모드에서도 돌아가는걸 볼 수 있음

public class AroundBall : MonoBehaviour
{
    //Rotation Direction
    //CW: Clock-Wise (시계방향)
    //CCW: Counter Clockwise (반시계방향)
    public enum ERotDir { CW, CCW }
    public enum ERotType { Pitch, Yaw, Roll }

    //#region (이름) ~ #endregion : 접어놓을 수 있음
    //[Header(" ")] : 단락 나눌 수 있음
    #region Public Variables
    [Header("- Game Objects -")]
    [SerializeField] private GameObject ballPrefab = null;
    [SerializeField] private Transform targetTr = null;

    [Header("- Values -")]
    [SerializeField, Range(0f, 300f)] private float speed = 100f; //공이 도는 속도
    [SerializeField, Range(0f, 10f)] private float distance = 1f; //공과 플레이어의 거리

    [Header("- Type -")]
    [SerializeField] private ERotDir rotDir = ERotDir.CCW;
    [SerializeField] private ERotType rotType = ERotType.Yaw;
    #endregion

    private Transform ballTr = null;

    private float angle = 0f;

    private void Awake()
    {
        //ballTr = transform.GetChild(0); //자식을 들고와 관리함
        //Debug.Log(ballTr.name);

        if (ballPrefab == null)
        {
            Debug.LogError("ballPrefab is missing!");
            return;
        }

        GameObject go = Instantiate(ballPrefab);
        //go.transform.parent = transform;
        go.transform.SetParent(transform); //ballPrefab인 gameobject go의 부모가 됨
        ballTr = go.transform;
    }

    private void Update()
    {
        if (targetTr == null) return; //타겟이 중간에 없어지면 return

        //Clamp
        switch (rotDir)
        {
            case ERotDir.CW:
                angle -= Time.deltaTime * speed;
                if (angle < 0f) angle = 360f;
                break;
            case ERotDir.CCW:
                angle += Time.deltaTime * speed;
                if (angle > 360f) angle = 0f;
                break;
        }

        Vector3 anglePos = new Vector3();
        CalcAnglePosWithPosType(rotType, angle, ref anglePos);
        
        //타겟을 따라가기
        Vector3 targetPos = targetTr.position;
        ballTr.position = targetTr.position + (anglePos * distance);
    }

    //ref: 참조, out: 아예바꿈
    private void CalcAnglePosWithPosType(ERotType _rotType, float _angle, ref Vector3 _pos)
    {
        float angle2Rad = _angle * Mathf.Deg2Rad;
        switch (_rotType)
        {
            case ERotType.Pitch:
                _pos.x = 0f;
                _pos.y = Mathf.Sin(angle2Rad);
                _pos.z = Mathf.Cos(angle2Rad);
                break;
            case ERotType.Yaw:
                _pos.x = Mathf.Cos(angle2Rad);
                _pos.y = 0f;
                _pos.z = Mathf.Sin(angle2Rad);
                break;
            case ERotType.Roll:
                _pos.x = Mathf.Cos(angle2Rad);
                _pos.y = Mathf.Sin(angle2Rad);
                _pos.z = 0f;
                break;
        }
    }

}
