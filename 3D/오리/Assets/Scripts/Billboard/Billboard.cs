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
        //GetComponentInChildren<Billboard>(); //Billboard�ڽĿ��Լ� ������Ʈ�� ������
        //GetComponentsInChildren<Billboard>(); //Billboard�ڽ�'��'���Լ� ������Ʈ�� ������
        //transform.GetChiled; //�ڽĿ��Լ� transform�� ������
        //GameObject.Find //gameobjectã�ƿ�(��� gameobject�� �˻��ؾ��ؼ�... �� ����?)
        apj = GetComponentInChildren<AnchorPivotJoint>();
        screen = GetComponentInChildren<Screen>();
    }

    private void Start()
    {
        //���1: �ڷ������� ����(���ϸ��̾�)
        VideoClip clip = Resources.Load<VideoClip>("Videos\\imase_NIGHT_DANCER");
        /*
        //���2: ���������� ����ȯ��
        clip = Resources.Load("Videos\\imase_NIGHT_DANCER") as VideoClip;
        //���3: ���������ȯ���
        clip = (VideoClip)Resources.Load("Videos\\imase_NIGHT_DANCER");
        */

        screen.SetVideoClip(clip);
    }

    private void Update()
    {
        float angleRad = CalcAngleToTarget();
        apj.Yaw((90f + 180f) - (angleRad * Mathf.Rad2Deg)); //90f + 180f �� ������ �������ذ���

        float dist = CalcDistanceWithTarget();
        if (dist < scrPlayDist) screen.Play();
        else screen.Pause();

        DebugDistance();
    }

    private float CalcAngleToTarget()
    {
        //���⺤�� ���ϱ�
        Vector3 dirToTarget = targetTr.position - transform.position; //target���� ���ϴ� ����
        dirToTarget.Normalize();

        //���̰� 1�� ���͸� �����: ������ �� ������ ������ ���̷� ������.

        //Atan(y / x);
        return Mathf.Atan2(dirToTarget.z, dirToTarget.x); //�������ϱ�(Atan2)
    }

    private float CalcDistanceWithTarget()
    {
        Vector3 dirToTarget = targetTr.position - transform.position;
        //���1 (magnitude�� �Ÿ�)
        float dist = dirToTarget.magnitude; 
        //���2
        dist = Vector3.Distance(targetTr.position, transform.position);

        return dist;
    }

    //������ ����ϰ� ���� �Ÿ����� ������, �ƴҶ� ������� ��Ÿ��
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
