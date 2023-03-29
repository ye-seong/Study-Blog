using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//[ExecuteInEditMode] //�̰� ���̸� �����尡 �ƴ� ������忡���� ���ư��°� �� �� ����

public class AroundBall : MonoBehaviour
{
    //Rotation Direction
    //CW: Clock-Wise (�ð����)
    //CCW: Counter Clockwise (�ݽð����)
    public enum ERotDir { CW, CCW }
    public enum ERotType { Pitch, Yaw, Roll }

    //#region (�̸�) ~ #endregion : ������� �� ����
    //[Header(" ")] : �ܶ� ���� �� ����
    #region Public Variables
    [Header("- Game Objects -")]
    [SerializeField] private GameObject ballPrefab = null;
    [SerializeField] private Transform targetTr = null;

    [Header("- Values -")]
    [SerializeField, Range(0f, 300f)] private float speed = 100f; //���� ���� �ӵ�
    [SerializeField, Range(0f, 10f)] private float distance = 1f; //���� �÷��̾��� �Ÿ�

    [Header("- Type -")]
    [SerializeField] private ERotDir rotDir = ERotDir.CCW;
    [SerializeField] private ERotType rotType = ERotType.Yaw;
    #endregion

    private Transform ballTr = null;

    private float angle = 0f;

    private void Awake()
    {
        //ballTr = transform.GetChild(0); //�ڽ��� ���� ������
        //Debug.Log(ballTr.name);

        if (ballPrefab == null)
        {
            Debug.LogError("ballPrefab is missing!");
            return;
        }

        GameObject go = Instantiate(ballPrefab);
        //go.transform.parent = transform;
        go.transform.SetParent(transform); //ballPrefab�� gameobject go�� �θ� ��
        ballTr = go.transform;
    }

    private void Update()
    {
        if (targetTr == null) return; //Ÿ���� �߰��� �������� return

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
        
        //Ÿ���� ���󰡱�
        Vector3 targetPos = targetTr.position;
        ballTr.position = targetTr.position + (anglePos * distance);
    }

    //ref: ����, out: �ƿ��ٲ�
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
